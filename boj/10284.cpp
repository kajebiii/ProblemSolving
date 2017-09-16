#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 15e2 + 100;

int N, Nr[MAX_N], Sum[MAX_N], Wait[MAX_N];
int Dy[MAX_N];
int getSum(int a, int b) {return Sum[b] - Sum[a-1];}
int getWait(int a, int b) {return Wait[b] - Wait[a-1] - (N+1-b) * (Sum[b] - Sum[a-1]);}
int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d", &N);
		for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
		for(int i=1; i<=N; i++) Sum[i] = Sum[i-1] + Nr[i];
		for(int i=1; i<=N; i++) Wait[i] = Wait[i-1] + (N+1-i) * Nr[i];
		for(int i=1; i<=N; i++) Dy[i] = 0x7fffffff;
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=i; j++)
				Dy[i] = min(Dy[i], Dy[j-1] + getWait(j, i) + getSum(i+1, N));
		}
		printf("%d\n", Dy[N]);
	}
	return 0;
}
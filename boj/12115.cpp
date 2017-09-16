#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e3 + 100;

int N, M, Q;
int Nr[MAX_N][MAX_N];
int Data[MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) scanf("%d", &Nr[i][j]);
	scanf("%d", &Q);
	for(int q=0; q<Q; q++) {
		for(int i=0; i<M; i++) scanf("%d", &Data[i]);
		int cnt = 0;
		for(int i=0; i<N; i++) {
			bool isGood = true;
			for(int j=0; j<M; j++) {
				if(Data[j] == -1) continue;
				if(Data[j] != Nr[i][j]) {isGood = false; break;}
			}
			if(isGood) cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
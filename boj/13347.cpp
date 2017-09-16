#include <stdio.h>
#include <algorithm>
#include <vector> 

using namespace std;

const int MAX_N = 2e1 + 5;

int N, M;
vector<int> Ed[MAX_N]; int Cnt[MAX_N];
double P[MAX_N], V[MAX_N];
int main() {
	scanf("%d%d", &N, &M);
	while(M--) {
		int a, b; scanf("%d%d", &a, &b);
		Ed[a].push_back(b); Ed[b].push_back(a);
		Cnt[a]++; Cnt[b]++;
	}
	Ed[0].push_back(N); P[N] = 1; V[N] = -1; Cnt[N]++;
	for(int it=0; it<50000; it++) {
		for(int i=0; i<N; i++) {
			P[i] = 0;
			V[i] = 0;
			for(int x : Ed[i]) {
				if(x == N-1) continue;
				P[i] += P[x] / Cnt[x];
				V[i] += (P[x] + V[x]) / Cnt[x];
			}
		}
	}
	printf("%f\n", V[N-1]);
	return 0;
}
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

const int MAX_N = 1e2 + 10;

int N, M, K, F[MAX_N], Calc[MAX_N][26];
char S[MAX_N], P[MAX_N];

const int fre = 0;
int main() {
	if(fre) freopen("input.txt", "r", stdin);
	if(fre) freopen("output.txt", "w", stdout);
	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++) {
		scanf("%d%d%d", &N, &M, &K);
		scanf("%s%s", S+1, P+1);

		F[1] = 0; 
		for(int k=0, i=2; i<=M; i++) {
			while(k && P[i] != P[k+1]) k = F[k];
			if(P[i] == P[k+1]) k++;
			F[i] = k;
		}
		for(int i=0; i<M; i++) {
			for(char j='A'; j<='Z'; j++) {
				int x = i;
				while(x && j != P[x+1]) x = F[x];
				if(j == P[x+1]) x++;
				Calc[i][j-'A'] = x;
			}
		}

		vector<int> maxV = vector<int>(M+1, 0);
		vector<double> dy = vector<double>(M+1, 0);
		vector<double> pr = vector<double>(M+1, 0); pr[0] = 1;
		for(int l=1; l<=K; l++) {
			vector<int> nmaxV = vector<int>(M+1, 0);
			vector<double> ndy = vector<double>(M+1, 0);
			vector<double> npr = vector<double>(M+1, 0);
			for(int i=0; i<M; i++) if(pr[i] > 0)
				for(int j=1; j<=N; j++) {
					int nt = Calc[i][S[j]-'A'];
					double nd = dy[i], np = pr[i] / N; int val = maxV[i];
					if(nt == M) {nd += 1, val += 1, nt = F[nt];}
					npr[nt] += np;
					ndy[nt] += nd * np;
					nmaxV[nt] = max(nmaxV[nt], val);
				}
			for(int i=0; i<M; i++) if(npr[i] > 0)
				ndy[i] /= npr[i];
			
			dy = ndy, pr = npr; maxV = nmaxV;
//			for(int i=0; i<M; i++) printf("%d(%c) : %f %f %d\n", i, P[i], dy[i], pr[i], maxV[i]);
		}
		double ans = 0; int maxB = 0;
		for(int i=0; i<M; i++) ans += dy[i] * pr[i], maxB = max(maxB, maxV[i]);
//		printf("[%d]\n", maxB);
		printf("Case #%d: %.10f\n", tc, maxB - ans);
	}
	return 0;
}
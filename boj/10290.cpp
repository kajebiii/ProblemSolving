#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <tuple>

using namespace std;

const int MAX_N = 5e1;
typedef pair<pair<int, int>, int> ppi;

int K, N, M;
int Chk[MAX_N][MAX_N], Cnt[MAX_N][MAX_N];
char Mp[MAX_N][MAX_N];
char S[MAX_N];

int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d%d", &K, &N, &M);
		for(int i=0; i<N; i++) scanf("%s", Mp[i]);
		for(int i=0; i<N; i++) for(int j=0; j<M; j++)
			Chk[i][j] = 0;
		bool noSol = false;
		bool ambi = false;
		while(K--) {
			scanf("%s", S); int SN = strlen(S);
			if(noSol) continue;

			int cntA = 0;
			for(int i=0; i<N; i++) for(int j=0; j<M; j++) Cnt[i][j] = 0;
			for(int i=0; i<N; i++) for(int j=0; j<M; j++) {
				for(int d=0; d<8; d++) {
					int dx = "11202020"[d] - '1';
					int dy = "20112002"[d] - '1';
					int lastX = i + dx * (SN-1), lastY = j + dy * (SN-1);
					if(lastX < 0 || lastY < 0) continue;
					if(lastX >= N || lastY >= M) continue;

					bool chk = true;
					for(int k=0; k<SN; k++)
						if(Mp[i+dx*k][j+dy*k] != S[k]) { chk = false; break; }
					if(chk) {
						cntA++;
						for(int k=0; k<SN; k++) {
							Cnt[i+dx*k][j+dy*k] = 1;
							Chk[i+dx*k][j+dy*k] = 1;
						}
					}
				}
			}
			if(cntA == 0) {noSol = true; continue;}
			int allC = 0;
			for(int i=0; i<N; i++) for(int j=0; j<M; j++) allC += Cnt[i][j];
			if(allC > SN) {ambi = true; continue;}
		}

		if(noSol) {puts("no solution"); continue; }
		for(int i=0; i<N; i++) for(int j=0; j<M; j++)
			if(Chk[i][j] == 2) {ambi = true; break;}
		if(ambi) {puts("ambiguous"); continue; }
		bool printed = false;
		for(int i=0; i<N; i++) for(int j=0; j<M; j++) 
			if(Chk[i][j] == 0) {
				printf("%c", Mp[i][j]);
				printed = true;
			}
		if(printed == false) puts("empty solution");
		else puts("");
	}
	return 0;
}
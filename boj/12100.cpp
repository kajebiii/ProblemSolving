#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 2e1 + 5, MAX_T = 5;
int Nr[MAX_N][MAX_N], N, Ans = 0;
int Memo[MAX_T][MAX_N][MAX_N];
void dfs(int d) {
	int val = 0;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) val = max(val, Nr[i][j]);
	Ans = max(Ans, val);
	if(d == MAX_T) return;
	if(Ans >= (val * (1 << (MAX_T-d)))) return;

	for(int i=0; i<N; i++) for(int j=0; j<N; j++) Memo[d][i][j] = Nr[i][j];
	for(int k=0; k<4; k++) {
		//Nr <-
		for(int i=0; i<N; i++) {
			int ix = 0, val = 0;
			for(int j=0; j<N; j++) {
				if(Nr[i][j] == 0) continue;
				if(val == 0) val = Nr[i][j];
				else if(val == Nr[i][j]) {
					Nr[i][ix++] = val * 2;
					val = 0;
				}else Nr[i][ix++] = val, val = Nr[i][j];
			}
			if(val != 0) Nr[i][ix++] = val;
			for(int j=ix; j<N; j++) Nr[i][j] = 0;
		}
		dfs(d+1);
		//Nr <- Memo 
		for(int i=0; i<N; i++) for(int j=0; j<N; j++) Nr[i][j] = Memo[d][i][j];
		//Memo <- Nr rotate
		for(int i=0; i<N; i++) for(int j=0; j<N; j++) Memo[d][i][j] = Nr[N-1-j][i];
		//Nr <- Memo
		for(int i=0; i<N; i++) for(int j=0; j<N; j++) Nr[i][j] = Memo[d][i][j];
	}
}
const int fre = 0;
int main() {
	if(fre) freopen("input.txt", "r", stdin);
	scanf("%d", &N); int maxV = 0; for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d", &Nr[i][j]), maxV = max(maxV, Nr[i][j]);
	Ans = maxV;
	dfs(0);
	printf("%d\n", Ans);
	return 0;
}
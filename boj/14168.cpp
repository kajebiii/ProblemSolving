#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e3 + 10, INF = 0x7fffffff;

int N[2], Dy[MAX_N][MAX_N][2], Nr[2][MAX_N][2];

const int fre = 0;
int main() {
	if(fre) freopen("checklist.in", "r", stdin);
	if(fre) freopen("checklist.out", "w", stdout);

	for(int k=0; k<2; k++) scanf("%d", &N[k]);
	for(int k=0; k<2; k++) for(int i=1; i<=N[k]; i++) for(int j=0; j<2; j++) scanf("%d", &Nr[k][i][j]);
	for(int i=0; i<=N[0]; i++) for(int j=0; j<=N[1]; j++) for(int k=0; k<2; k++) Dy[i][j][k] = INF;
	Dy[1][0][0] = 0;

	auto getDis = [&](int a, int ai, int b, int bi) {
		int dx = Nr[a][ai][0] - Nr[b][bi][0], dy = Nr[a][ai][1] - Nr[b][bi][1];
		return dx * dx + dy * dy;
	};
	for(int i=0; i<=N[0]; i++) for(int j=0; j<=N[1]; j++) for(int k=0; k<2; k++) {
		if(Dy[i][j][k] == INF) continue;
		for(int l=0; l<2; l++) {
			int ni = i + 1 - l, nj = j + l;
			if(ni > N[0] || nj > N[1]) continue;
			int nw[2] ={i, j}, nt[2] = {ni, nj};
			Dy[ni][nj][l] = min(Dy[ni][nj][l], Dy[i][j][k] + getDis(k, nw[k], l, nt[l]));
		}
	}
	printf("%d\n", Dy[N[0]][N[1]][0]);
	return 0;
}
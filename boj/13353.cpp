#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

const int MAX_N = 1e2 + 10, MAX_M = 2e2 + 20;

int N, M, Nr[MAX_M][2];
int Mat[MAX_N][MAX_M + 1]; // [M | Y]
int X[MAX_M];
vector<int> Choose[MAX_N];
int rp[MAX_N], cp[MAX_M];

int main() {
	scanf("%d%d", &N, &M);
	for(int j=0; j<M; j++) {
		int x, y; scanf("%d%d", &x, &y);
		Mat[x][j] = Mat[y][j] = 1;
		Mat[x][M] = 1 - Mat[x][M];
		Nr[j][0] = x; Nr[j][1] = y;
	}
	if(M % 2 == 1) { puts("impossible"); return 0; }

	for(int i=0; i<N; i++) rp[i] = -1;
	for(int j=0; j<M; j++) {
		int ix = -1;
		for(int i=0; i<N; i++) if(rp[i] == -1 && Mat[i][j] == 1) {
			ix = i;
			break;
		}
		if(ix == -1) continue;
		rp[ix] = j;
		cp[j] = ix;
		for(int i=0; i<N; i++) if(i != ix && Mat[i][j] == 1)
			for(int k=0; k<=M; k++)
				Mat[i][k] ^= Mat[ix][k];
	}

	for(int j=0; j<M; j++) X[j] = 0;
	for(int i=0; i<N; i++) {
		if(rp[i] != -1) {
			X[rp[i]] = Mat[i][M];
		} else {
			assert(Mat[i][M] == 0);
		}
	}
	for(int j=0; j<M; j++)
		Choose[Nr[j][X[j]]].push_back(j);
	for(int i=0; i<N; i++)
		for(int j=0; j<Choose[i].size(); j+=2)
			printf("%d %d\n", Choose[i][j], Choose[i][j+1]);
	return 0;
}

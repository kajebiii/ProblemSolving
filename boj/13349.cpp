#include <algorithm>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <tuple>

using namespace std;

const int MAX_N = 1e3 + 10;
typedef pair<int, int> pi;

int N, M, Nr[MAX_N][MAX_N];
bool Chk[MAX_N][MAX_N];
bool isPossible(int m) {
	queue<pi> Q; Q.push(make_pair(N-1, M-1));
	memset(Chk, false, sizeof Chk);
	Chk[N-1][M-1] = true;
	while(!Q.empty()) {
		int x, y; tie(x, y) = Q.front(); Q.pop();
		for(int k=0; k<4; k++) {
			int nx = x + "1012"[k] - '1';
			int ny = y + "0121"[k] - '1';
			if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if(Chk[nx][ny]) continue;
			if(Nr[nx][ny] < Nr[x][y] - m) continue;
			Chk[nx][ny] = true;
			Q.push(make_pair(nx, ny));
		}
	}
	return Chk[0][0];
}
int main() {
	scanf("%d%d", &N, &M); 
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) scanf("%d", &Nr[i][j]);
	
	int ans = -1;
	for(int l=0, r=0x3fffffff; l<=r; ) {
		int m = (l+r) >> 1;
		if(isPossible(m)) {
			ans = m;
			r = m - 1;
		}else l = m + 1;
	}
	printf("%d\n", ans);
	return 0;
}
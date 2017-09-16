#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

const int MAX_N = 1e2 + 10, INF = 0x7fffffff;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int N, M; char Mp[MAX_N][MAX_N];
int Dis[3][MAX_N][MAX_N];
void getDis(pi s, int k) {
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) Dis[k][i][j] = INF;
	priority_queue<pii, vector<pii>, greater<pii>> Q;
	Q.push(make_pair(0, s)); Dis[k][s.first][s.second] = 0;
	while(!Q.empty()) {
		int nc; pi now; int x, y; tie(nc, now) = Q.top(); Q.pop();
		tie(x, y) = now;
		for(int l=0; l<4; l++) {
			int nx = x + "0121"[l] - '1';
			int ny = y + "1012"[l] - '1';
			if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			int c = 0; if(Mp[nx][ny] == '#') c = 1;
			if(Mp[nx][ny] == '*') continue;
			if(Dis[k][nx][ny] > nc + c) {
				Dis[k][nx][ny] = nc + c;
				Q.push(make_pair(Dis[k][nx][ny], make_pair(nx, ny)));
			}
		}
	}
}
int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d", &N, &M);
		for(int i=1; i<=N; i++) scanf("%s", Mp[i] + 1);
		for(int i=0; i<=N+1; i++) Mp[i][0] = Mp[i][M+1] = '.';
		for(int i=0; i<=M+1; i++) Mp[0][i] = Mp[N+1][i] = '.';
		N += 2; M += 2; // and 0-base;

		vector<pi> list; list.emplace_back(0, 0);
		for(int i=0; i<N; i++) for(int j=0; j<M; j++) if(Mp[i][j] == '$')
			list.emplace_back(i, j);
		for(int i=0; i<3; i++)
			getDis(list[i], i);

		int ans = INF;
		for(int i=0; i<N; i++) for(int j=0; j<M; j++)
			if(Dis[0][i][j] != INF && Dis[1][i][j] != INF && Dis[2][i][j] != INF)
				ans = min(ans, Dis[0][i][j] + Dis[1][i][j] + Dis[2][i][j] - ((Mp[i][j] == '#')?2:0) );
		printf("%d\n", ans);
	}
	return 0;
}
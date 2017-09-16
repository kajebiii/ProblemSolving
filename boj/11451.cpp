#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <tuple>

using namespace std;

const int MAX_N = (5e1 + 10)*(5e1 + 10), INF = 0x7fffffff;

typedef pair<int, int> pi;

int N, M; char Mp[MAX_N][MAX_N];
pi P[MAX_N][MAX_N]; int W[MAX_N][MAX_N];
int toNr(int x, int y) { return x*M+y; }
int toNr(pi k) { return k.first*M+k.second; }
pi toPi(int v) {return make_pair(v/M, v%M);}
pi toGo(int v, int k) {
	pi val = toPi(v);
	int x = val.first + "1012"[k] - '1';
	int y = val.second + "0121"[k] - '1';
	return make_pair(x, y);
}

int main() {
	int T; scanf("%d", &T); 
	while(T--) {
		scanf("%d%d", &N, &M);
		for(int i=0; i<N; i++) scanf("%s", Mp[i]);
		int wh[2] = {-1, -1}, cnt = 0;
		for(int i=0; i<N; i++) for(int j=0; j<M; j++) if(Mp[i][j] == 'P')
			wh[cnt++] = toNr(i, j);
		assert(cnt == 2);

		vector<vector<int>> dis = vector<vector<int>>(N*M, vector<int>(N*M, INF));
		queue<pi> Q; 
		Q.push(make_pair(wh[0], wh[1])); 
		dis[wh[0]][wh[1]] = 0;

		int ans[2] = {-1, -1};
		while(!Q.empty()) {
			int val[2] = {Q.front().first, Q.front().second}; Q.pop();
			if(val[0] == val[1]) {ans[0] = val[0], ans[1] = val[1]; break;}
			int d = dis[val[0]][val[1]];
			for(int k=0; k<4; k++) {
				pi next[2] = {toGo(val[0], k), toGo(val[1], k)};
				bool isCan = true;
				for(int l=0; l<2; l++) {
					int x, y; tie(x, y) = next[l];
					if(x<0) x=N-1; if(y<0) y=M-1;
					if(x>=N) x=0;  if(y>=M) y=0;
					next[l] = make_pair(x, y);
					if(Mp[x][y] == 'G') {isCan = false; break;}
					if(Mp[x][y] == 'X') next[l] = toPi(val[l]);
				}
				if(isCan == false) continue;
				int to[2] = {toNr(next[0]), toNr(next[1])};
				if(dis[to[0]][to[1]] != INF) continue;
				dis[to[0]][to[1]] = d+1;
				Q.push(make_pair(to[0], to[1]));
				P[to[0]][to[1]] = make_pair(val[0], val[1]);
				W[to[0]][to[1]] = k;
			}
		}
		if(ans[0] == -1) puts("IMPOSSIBLE");
		else {
			printf("%d ", dis[ans[0]][ans[1]]);
			vector<int> how;
			for(int i=ans[0], j=ans[1]; (i!=wh[0] || j!=wh[1]); ) {
				int ni = P[i][j].first, nj = P[i][j].second;
				how.push_back(W[i][j]);
				if(i == 0 && j == 0) break;
				i = ni; j = nj;
			}
			reverse(how.begin(), how.end());
			for(int x : how) printf("%c", "WNES"[x]);
			puts("");
		}
	}
	return 0;
}
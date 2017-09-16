#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;

const int MAX_N = 1e2 + 10;

int N, Nr[MAX_N];
struct ED {
	int w;
	bool chk[MAX_N];
	ED() {
		w = -1;
		for(int i=1; i<=N; i++) chk[i] = false;
	}
};
vector<ED> Ed[MAX_N];

int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		int k; scanf("%d%d", &k, &Nr[i]);
		while(k--) {
			int s, w; scanf("%d%d", &s, &w);
			ED e; e.w = w;
			while(s--) {
				int x; scanf("%d", &x);
				e.chk[x] = true;
			}
			Ed[i].push_back(e);
		}
	}

	vector<vector<int>> dis = vector<vector<int>>(N+1, vector<int>(N+1, INF));
	vector<vector<bool>> vis = vector<vector<bool>>(N+1, vector<bool>(N+1, false));
	priority_queue<pi, vector<pi>, greater<pi> > Q; Q.push(make_pair(Nr[1], 1 * (N+1) + 0)); dis[1][0] = Nr[1];

	int ans = -1;
	while(!Q.empty()) {
		int c, v, f, temp; tie(c, temp) = Q.top(); Q.pop();
		v = temp / (N+1); f = temp % (N+1);
		vis[v][f] = true;
//		printf("%d %d -> %d\n", v, f, c);
		if(v == N) {
			ans = c;
			break;
		}
		
		for(ED &e : Ed[v]) {
			if(dis[e.w][v] <= dis[v][f] + Nr[e.w]) continue;
			if(e.chk[f] == true) continue;
			if(vis[e.w][v] == true) continue;
			vis[e.w][v] = true;
			Q.push(make_pair(dis[e.w][v] = dis[v][f] + Nr[e.w], e.w * (N+1) + v));
		}
	}
	if(ans == -1) puts("impossible"); else printf("%d\n", ans);
	return 0;
}
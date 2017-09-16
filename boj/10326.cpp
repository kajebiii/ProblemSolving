#include <stdio.h>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <functional>

using namespace std;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX_N = 1e3 + 10, MAX_S = 120 + 10, INF = 0x7fffffff;

int N, M, S, F, St, En;
vector<pi> Ed[MAX_N], NEd[MAX_N];
int Dis[MAX_N][MAX_N], Price[MAX_N];
int NDis[MAX_N][MAX_N]; bool Vis[MAX_N][MAX_N];

const int debug = 0, fre = 0;
int main() {
	if(fre) { freopen("input.txt", "r", stdin); }
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d%d%d", &N, &M, &S, &F);
		for(int i=0, x, y, c; i<M; i++) {
			scanf("%d%d%d", &x, &y, &c);
			Ed[y].emplace_back(x, c);
			Ed[x].emplace_back(y, c);
		}
		vector<int> list;
		for(int i=1; i<=N; i++) Price[i] = -1;
		for(int i=0, x, c; i<S; i++) {
			scanf("%d%d", &x, &c);
			Price[x] = c;
			list.push_back(x);
		}
		scanf("%d%d", &St, &En);
		list.push_back(St), list.push_back(En);
		sort(list.begin(), list.end());
		list.erase(unique(list.begin(), list.end()), list.end());
		auto getDis = [&](int v, int dis[MAX_N], vector<pi> ed[], bool fast) {
			for(int i=1; i<=N; i++) dis[i] = INF;
			vector<bool> vis = vector<bool>(N+1, false);
			priority_queue<pi, vector<pi>, greater<pi>> Q;
			Q.push(make_pair(0, v)); dis[v] = 0;
			while(!Q.empty()) {
				int nc, v; tie(nc, v) = Q.top(); Q.pop();
				if(vis[v]) continue; vis[v] = true;
				for(pi &e : ed[v]) {
					int w, c; tie(w, c) = e;
					if(dis[w] > dis[v] + c && (!fast || dis[v] + c <= F))
						Q.push(make_pair(dis[w] = dis[v]+c, w));
				}
			}
		};
		for(int v : list) {
			if(Price[v] == -1) continue;
			getDis(v, Dis[v], Ed, 1);
		}

		//
		if(debug) printf("??\n");

		priority_queue<pii, vector<pii>, greater<pii> > Q;
		for(int v : list) for(int w : list)
			NDis[v][w] = INF, Vis[v][w] = false;
		for(int v : list) 
			NDis[v][0] = INF, Vis[v][0] = false;

		Q.push(make_pair(0, make_pair(St, 0)));
		NDis[St][0] = 0;
		while(!Q.empty()) {
			pi getV;
			int nc, v, ix; tie(nc, getV) = Q.top(); Q.pop();
			tie(v, ix) = getV;
			if(Vis[v][ix]) continue; Vis[v][ix] = true;
			if(debug) printf("v %d / ix %d : %d\n", v, ix, NDis[v][ix]);
			if(v == En) {
				printf("%d\n", nc);
				break;
			}
			for(int w : list) {
				if(w == v) continue;
				if(Dis[v][w] > F) continue;
				int now = 0; if(ix != 0) now = F - Dis[ix][v];
				if(debug) printf("[v %d w %d][Dis %d > now %d]\n", v, w, Dis[v][w], now);
				if(Dis[v][w] > now && NDis[w][0] > nc + Price[v] * (Dis[v][w] - now) )
					Q.push(make_pair(NDis[w][0] = nc + Price[v] * (Dis[v][w] - now), make_pair(w, 0)));
				if(NDis[w][v] > nc + Price[v] * (F - now) )
					Q.push(make_pair(NDis[w][v] = nc + Price[v] * (F - now), make_pair(w, v)));
			}
		}



		for(int i=1; i<=N; i++) Ed[i].clear(), Ed[i].shrink_to_fit();
		for(int v : list) NEd[v].clear(), NEd[v].shrink_to_fit();
	}
	return 0;
}
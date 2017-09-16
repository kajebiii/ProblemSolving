#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <tuple>

using namespace std;

const int MAX_N = 2e3 + 10, INF = 0x7fffffff;
typedef pair<int, int> pi;

int N, M, T, S, G, H, Cnt[MAX_N];
vector<pi> Ed[MAX_N];
vector<int> GEd[MAX_N];


int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d%d%d%d%d", &N, &M, &T, &S, &G, &H);
		while(M--) {
			int x, y, c; scanf("%d%d%d", &x, &y, &c);
			Ed[x].emplace_back(y, c);
			Ed[y].emplace_back(x, c);
		}
		//
		vector<int> dis = vector<int>(N+1, INF);
		vector<bool> vis = vector<bool>(N+1, false);
		priority_queue<pi, vector<pi>, greater<pi>> Q;
		Q.push(make_pair(0, S)); dis[S] = 0;
		while(!Q.empty()) {
			int c, v; tie(c, v) = Q.top(); Q.pop();
			if(vis[v] == true) continue; vis[v] = true;
			for(auto &e : Ed[v]) {
				int w, co; tie(w, co) = e;
				if(dis[w] > c + co)
					Q.push(make_pair(dis[w] = c + co, w));
			}
		}
		//
		for(int v=1; v<=N; v++)
			for(auto &e : Ed[v]) {
				int w, co; tie(w, co) = e;
				if(dis[w] == dis[v] + co)
					GEd[v].push_back(w);
			}
		//
		int newS = G;
		if(dis[H] > dis[G]) newS = H;
		for(int i=1; i<=N; i++) Cnt[i] = 0;
		while(T--) {int x; scanf("%d", &x);Cnt[x]++;}
		vis = vector<bool>(N+1, false);
		queue<int> GQ; GQ.push(newS); vis[newS] = true;
		while(!GQ.empty()) {
			int v = GQ.front(); GQ.pop();
			Cnt[v]++;
			for(int w : GEd[v]) {
				if(vis[w] == true) continue;
				vis[w] = true;
				GQ.push(w);
			}
		}
		for(int i=1; i<=N; i++) if(Cnt[i] == 2) printf("%d ", i); puts("");
		//
		for(int i=1; i<=N; i++) {
			Ed[i].clear(); Ed[i].shrink_to_fit();
			GEd[i].clear(); GEd[i].shrink_to_fit();
		}
	}
	return 0;
}
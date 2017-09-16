#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <tuple>

using namespace std;

const int MAX_N = 1e5 + 10, INF = 0x7fffffff;
typedef pair<int, int> pi;

struct PT {
	int x, y, ix;
	PT() {}
	PT(int x_, int y_, int i_) : x(x_), y(y_), ix(i_) {}
};
int N;
vector<PT> Ps;
vector<pi> Ed[MAX_N * 2];

const int fre = 0;
int main() {
	if(fre) freopen("lasers.in", "r", stdin);
	if(fre) freopen("lasers.out", "w", stdout);

	auto pushPT = [&]() {
		int x, y; scanf("%d%d", &x, &y);
		int ix = Ps.size();
		Ps.emplace_back(x, y, ix);
	};
	scanf("%d", &N); N += 2; for(int i=0; i<N; i++) pushPT();
	// [0 (0 or 1)] -> [1 (2 or 3)]

	auto addEdge = [&](int a, int b, int c) {
		Ed[a].emplace_back(b, c);
		Ed[b].emplace_back(a, c);
	};
	sort(Ps.begin(), Ps.end(), [&](const PT &a, const PT &b) {return (a.x != b.x ? a.x < b.x : a.y < b.y);});
	for(int i=0; i<N-1; i++) if(Ps[i].x == Ps[i+1].x) addEdge(Ps[i].ix*2, Ps[i+1].ix*2, 0);
	sort(Ps.begin(), Ps.end(), [&](const PT &a, const PT &b) {return (a.y != b.y ? a.y < b.y : a.x < b.x);});
	for(int i=0; i<N-1; i++) if(Ps[i].y == Ps[i+1].y) addEdge(Ps[i].ix*2+1, Ps[i+1].ix*2+1, 0);
	for(int i=0; i<N; i++) addEdge(i*2, i*2+1, 1);

	vector<bool> vis = vector<bool>(N*2, 0);
	vector<int> dis = vector<int>(N*2, INF);
	priority_queue<pi, vector<pi>, greater<pi> > Q;
	Q.push(make_pair(0, 0)); Q.push(make_pair(0, 1)); dis[0] = dis[1] = 0;
	while(!Q.empty()) {
		int nc, v; tie(nc, v) = Q.top(); Q.pop();
		if(vis[v]) continue; vis[v] = true;
		for(pi &e : Ed[v]) {
			int w, c; tie(w, c) = e;
			if(dis[w] > dis[v] + c) Q.push(make_pair(dis[w] = dis[v] + c, w));
		}
	}
	int ans = min(dis[2], dis[3]); if(ans == INF) ans = -1;
	printf("%d\n", ans);
	return 0;
}
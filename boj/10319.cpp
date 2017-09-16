#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct ED {
	int to, fl, co, re;
	ED() {}
	ED(int t, int f, int c, int r) : to(t), fl(f), co(c), re(r) {}
};

const int MAX_N = 1e3 + 10;

int N, S, allP, T, FN, M;
vector<ED> Ed[MAX_N];
int St, En;

int dis[MAX_N], wh[MAX_N], ix[MAX_N]; bool inQ[MAX_N];
bool bfs() {
	for(int i=St; i<=En; i++) dis[i] = 1e9, inQ[i] = false;
	queue<int> Q; Q.push(St); inQ[St] = true; dis[St] = 0;
	while(!Q.empty()) {
		int v = Q.front(); Q.pop(); inQ[v] = false;
		for(int i=0; i<Ed[v].size(); i++) {
			ED &e = Ed[v][i];
			if(e.fl > 0 && dis[e.to] > dis[v] + e.co) {
				dis[e.to] = dis[v] + e.co;
				wh[e.to] = v;
				ix[e.to] = i;
				if(inQ[e.to] == false) inQ[e.to] = true, Q.push(e.to);
			}
		}
	}
	return dis[En] <= T;
}

int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d%d%d%d", &N, &S, &allP, &T, &FN);
		vector<int> Flist;
		for(int i=0, x; i<FN; i++) scanf("%d", &x), Flist.push_back(x);
		scanf("%d", &M);

		auto addEdge = [&](int fr, int to, int fl, int co) {
			Ed[fr].push_back(ED(to, fl, +co, Ed[to].size()));
			Ed[to].push_back(ED(fr,  0, -co, Ed[fr].size()-1));
		};
		for(int i=0, x, y, f, c; i<M; i++) {
			scanf("%d%d%d%d", &x, &y, &f, &c);
			addEdge(x, y, f, c);
		}
		St = 0; En = N+1;
		addEdge(St, S, allP, 0);
		for(int f : Flist) addEdge(f, En, allP, 0);

		//



		int flow = 0, cost = 0;
		while(bfs()) {
			int f = 1e9;
			for(int w = En, v, i; w != St; w = v) {
				v = wh[w]; i = ix[w];
				f = min(f, Ed[v][i].fl);
			}
			for(int w = En, v, i, r; w != St; w = v) {
				v = wh[w]; i = ix[w]; r = Ed[v][i].re;
				Ed[v][i].fl -= f; Ed[w][r].fl += f;
			}
			flow += f;
			cost += f * dis[En];
		}
		printf("%d\n", min(allP, flow*(T+1) - cost));

		//
		for(int i=St; i<=En; i++) Ed[i].clear(), Ed[i].shrink_to_fit();
	}
	return 0;
}
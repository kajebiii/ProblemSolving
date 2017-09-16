#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <tuple>

using namespace std;

const int MAX_N = 1e4 + 100;
typedef pair<int, int> pi;

int N, M, S;
vector<pi> Ed[MAX_N];

int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d%d", &N, &M, &S);
		while(M--) {
			int x, y, c; scanf("%d%d%d", &x, &y, &c);
			Ed[y].push_back(make_pair(x, c));
		}

		vector<int> dis = vector<int>(N+1, 0x7fffffff);
		vector<bool> vis = vector<bool>(N+1, false);
		priority_queue<pi, vector<pi>, greater<pi> > Q;
		Q.push(make_pair(0, S)); dis[S] = 0;
		int ansC = 0, maxV = 0;
		while(!Q.empty()) {
			int c, v; tie(c, v) = Q.top(); Q.pop();
			if(vis[v] == true) continue;
			vis[v] = true;
			ansC++; maxV = max(maxV, dis[v]);
			for(pi &e : Ed[v]) {
				int nc = c + e.second, w = e.first;
				if(vis[w] == true) continue;
				if(dis[w] > nc) Q.push(make_pair(dis[w] = nc, w));
			}
		}
		printf("%d %d\n", ansC, maxV);

		for(int i=1; i<=N; i++) {
			vector<pi> temp;
			Ed[i].swap(temp);
		}
	}
	return 0;
}
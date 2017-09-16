#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

const int MAX_N = 2e2 + 10, INF = 0x7fffffff;
typedef long long ll;
typedef pair<ll, int> pli;

int N, M, St, En, S, P, Y;
int calc(int per, int len) {
	return min(100 * (S + P * len), per * (Y + P * len));
}
struct ED {
	int to, co;
	ED() {}
	ED(int t_, int c_) : to(t_), co(c_) {}
};
vector<ED> Ed[MAX_N * 2];
int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d%d%d%d%d%d", &N, &M, &St, &En, &S, &P, &Y);
		
		for(int i=1; i<=N; i++) {
			Ed[i].emplace_back(i+N, 100 * S);
			Ed[i+N].emplace_back(i, 0);
		}
		while(M--) {
			int x, y, p, l; scanf("%d%d%d%d", &x, &y, &p, &l);
			int cost = calc(p, l);
			Ed[x].emplace_back(y, p * (Y + P * l));
			Ed[y].emplace_back(x, p * (Y + P * l));
			Ed[x+N].emplace_back(y+N, 100 * P * l);
			Ed[y+N].emplace_back(x+N, 100 * P * l);
		}
		vector<ll> dis = vector<ll>(2*N+1, 1ll*INF*INF);
		vector<bool> vis = vector<bool>(2*N+1, false);
		dis[St] = 0; 
		priority_queue<pli, vector<pli>, greater<pli> > Q;
		Q.push(make_pair(0ll, St));

		while(!Q.empty()) {
			long d; int v; tie(d, v) = Q.top(); Q.pop();
			if(vis[v] == true) continue; vis[v] = true;
			for(ED &e : Ed[v]) {
				int w = e.to, c = e.co;
				if(dis[w] > dis[v] + c)
					Q.push(make_pair(dis[w] = dis[v] + c, w));
			}
		}
		printf("%lld.%02d\n", dis[En]/100, dis[En]%100);

		for(int i=1; i<=2*N; i++) {Ed[i].clear(); Ed[i].shrink_to_fit();}
	}
	return 0;
}
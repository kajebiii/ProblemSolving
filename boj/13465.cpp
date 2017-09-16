#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

const int MAX_N = 1e5 + 100, INF = 0x7fffffff;
const ll LINF = 0x3fffffffffffffff;
int N, M, X;
vector<pli> Ed[MAX_N];

ll getDis(ll maxC) {
	vector<bool> vis = vector<bool>(N+1, false);
	vector<ll> dis = vector<ll>(N+1, LINF);
	priority_queue<pli, vector<pli>, greater<pli> > Q;
	Q.push(make_pair(0, 1)); dis[1] = 0;
	while(!Q.empty()) {
		ll d; int now; tie(d, now) = Q.top(); Q.pop();
		if(vis[now] == true) continue; vis[now] = true;
		for(auto &e : Ed[now])
		{
			int next; ll c; tie(c, next) = e;
			if(c > maxC) continue;
			if(vis[next]) continue;
			if(dis[next] > dis[now] + c)
				Q.push(make_pair(dis[next] = dis[now] + c, next));
		}
	}
	return dis[N];
}

int main() {
	scanf("%d%d%d", &N, &M, &X);
	for(int i=0; i<M; i++) {
		int x, y; ll c; scanf("%d%d%lld", &x, &y, &c);
		Ed[x].push_back(make_pair(c * 100, y));
		Ed[y].push_back(make_pair(c * 100, x));
	}
	ll fastDis = getDis(LINF);
	ll ans = -1;
	for(ll l=1, r=LINF; l<=r; ) {
		ll m = (l+r) >> 1;
		ll nowD = getDis(m);
		if(nowD <= fastDis / 100 * (100 + X))
			ans = m, r = m - 1;
		else
			l = m + 1;
	}
	printf("%lld\n", ans/100);
	return 0;
}
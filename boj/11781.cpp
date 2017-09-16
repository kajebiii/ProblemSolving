#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <tuple>
#include <assert.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
const int MAX_N = 5e3 + 100, INF = 0x7fffffff;
const ll LINF = 0x7fffffffffffffff;
struct ED {
	int to; ll co; int late;
	ED() {};
	ED(int t, ll c, int l) : to(t), co(c), late(l) {};
};
int N, M; ll S, E;
vector<ED> Ed[MAX_N];
ll calc(ll d, ll c, int l) {
	if(l == 0) return d + c;
	if(d + c <= S) return d + c;
	if(d >= E) return d + c;
	if(d < S) {
		ll rest = c - (S - d);
		return calc(S, rest, l);
	}
	if(d < E) {
		if(d + c*2 <= E) return d + c*2;
		ll rest = c - (E - d) / 2;
		return calc(E, rest, l);
	}
	assert(false);
	return -1;
}
int main() {
	scanf("%d%d%lld%lld", &N, &M, &S, &E);
	S *= 2; E *= 2;
	for(int i=0; i<M; i++) {
		int a, b; ll c; int t0, t1;
		scanf("%d%d%lld%d%d", &a, &b, &c, &t0, &t1);
		Ed[a].push_back(ED(b, c*2, t0));
		Ed[b].push_back(ED(a, c*2, t1));
	}
	
	vector<ll> dis = vector<ll>(N+1, LINF);
	priority_queue<pli, vector<pli>, greater<pli> > Q;
	dis[1] = 0; Q.push(make_pair(0, 1));
	while(!Q.empty()) {
		ll d; int v; tie(d, v) = Q.top(); Q.pop();
		if(dis[v] < d) continue;
		for(ED &e : Ed[v]) {
			ll nd = calc(d, e.co, e.late);
			int w = e.to;
			if(dis[w] > nd)
				Q.push(make_pair(dis[w] = nd, w));
		}
	}
	ll ans = 0;
	for(int i=1; i<=N; i++) ans = max(ans, dis[i]);
	printf("%lld", ans/2);
	if(ans%2 == 1) printf(".5");
	
	return 0;
}
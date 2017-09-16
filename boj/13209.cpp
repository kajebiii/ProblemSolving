#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define fi first
#define se second
#define pb push_back

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, 1), mp(1, 0), mp(0, -1)};
const int MAX_N = 1e5 + 100;

int N, K;
ll P[MAX_N];
vector<int> V[MAX_N];

pair<int, ll> find(int v, int p, ll m)
{
	pair<int, ll> result = mp(0, 0);
	vector<ll> List;
	for(int w : V[v])
	{
		if(w == p) continue;
		pair<int, ll> now = find(w, v, m);
		List.pb(now.se);
		result.fi += now.fi;
	}
	sort(List.begin(), List.end());
	ll now = P[v];
	for(ll x : List)
	{
		if(now + x <= m) now += x;
		else result.fi++;
	}
	List.clear();
	List.shrink_to_fit();
	result.se = now;
	return result;
}
int main()
{
	int T; cin >> T;
	while(T--)
	{
		scanf("%d%d", &N, &K);
		for(int i=1; i<=N; i++) scanf("%lld", &P[i]);
		for(int i=1; i<N; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			V[x].pb(y);
			V[y].pb(x);
		}

		ll s = 1, e = 1ll * INF * 100000, m, ans = -1;
		for(int i=1; i<=N; i++) s = max(s, P[i]);
		while(s <= e)
		{
			ll m = (s + e) / 2;
			if(find(1, -1, m).fi <= K) {ans = m; e = m - 1;}
			else s = m + 1;
		}
		printf("%lld\n", ans);
		for(int i=1; i<=N; i++)
		{
			V[i].clear();
			V[i].shrink_to_fit();
		}
	}
	return 0;
}

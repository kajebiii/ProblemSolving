#include <stdio.h>
#include <functional>
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
typedef tuple<int, int, int> ti;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) { return mp(x.fi+y.fi, x.se+y.se); }

const int INF = 0x7fffffff;
const pi Ch[4] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1) };

const int MAX_N = 1e4 + 10, MAX_K = 20 + 2;

int N, M, K;
int Dis[MAX_N][MAX_K];
vector<pi> Ed[MAX_N];

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;
	for(int i=0; i<M; i++)
	{
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		Ed[x].pb(mp(y, c));
		Ed[y].pb(mp(x, c));
	}

	for(int i=1; i<=N; i++) for(int k=K; k>=0; k--) Dis[i][k] = INF;
	Dis[1][K] = 0;
	priority_queue<ti, vector<ti>, greater<ti> > Q;
	Q.push(make_tuple(0, 1, K));
	while(!Q.empty())
	{
		int nct, nvtx, nfree;
		tie(nct, nvtx, nfree) = Q.top(); Q.pop();
		for(pi &temp : Ed[nvtx])
		{
			int vertex, cost;
			tie(vertex, cost) = temp;
			if(Dis[vertex][nfree] > nct + cost)
				Q.push(make_tuple(Dis[vertex][nfree] = nct + cost, vertex, nfree));
			if(nfree > 0) if(Dis[vertex][nfree-1] > nct + 0)
				Q.push(make_tuple(Dis[vertex][nfree-1] = nct, vertex, nfree-1));
		}
	}
	int ans = INF;
	for(int i=0; i<=K; i++) ans = min(ans, Dis[N][i]);
	cout << ans;
	return 0;
}
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

const int MAX_K = 1e2 + 5, MAX_N = 1e3 + 50;

int N, M, K;
int Dis[MAX_N][MAX_K], Cnt[MAX_N];
vector<pi> Ed[MAX_N];

int main() {
	if(debug) freopen("input.txt", "r", stdin);
	
	cin >> N >> M >> K;
	for(int i=0; i<M; i++)
	{
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		Ed[x].pb(mp(y, c));
	}
	priority_queue<pi, vector<pi>, greater<pi> > Q;
	Q.push(mp(0, 1));
	
	while(!Q.empty())
	{
		int nct, nve;
		tie(nct, nve) = Q.top(); Q.pop();
		if(Cnt[nve] >= K) continue;
		Dis[nve][++Cnt[nve]] = nct;

		for(pi &temp : Ed[nve])
		{
			int cost, vertex;
			tie(vertex, cost) = temp;
			if(Cnt[vertex] >= K) continue;
			Q.push(mp(cost + nct, vertex));
		}
	}
	for(int i=1; i<=N; i++) printf("%d\n", Cnt[i]<K?-1:Dis[i][K]);
	return 0;
}
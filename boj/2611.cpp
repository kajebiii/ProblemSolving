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

const int MAX_N = 1e3 + 100;

int N, M, InCnt[MAX_N], Dis[MAX_N], P[MAX_N];
vector<pi> V[MAX_N], ToOne;

void findAns(int v)
{
	if(v != 1) findAns(P[v]);
	printf("%d ", v);
}
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for(int i=0; i<M; i++)
	{
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		if(y != 1) V[x].pb(mp(y, c)), InCnt[y]++;
		else ToOne.pb(mp(x, c));
	}

	queue<int> Q; Q.push(1);
	while(!Q.empty())
	{
		int now = Q.front(); Q.pop();
		for(pi &temp : V[now])
		{
			int next, cost;
			tie(next, cost) = temp;
			Dis[next] = max(Dis[next], Dis[now] + cost);
			if(Dis[next] == Dis[now] + cost)
				P[next] = now;
			InCnt[next]--;
			if(InCnt[next] == 0) Q.push(next);
		}
	}
	int ans = 0, ansIx = -1;
	for(pi &temp : ToOne)
	{
		int to, cost; tie(to, cost) = temp;
		ans = max(Dis[to] + cost, ans);
		if(ans == Dis[to] + cost)
			ansIx = to;
	}
	printf("%d\n", ans);
	if(ansIx != -1) findAns(ansIx);
	printf("1");
	return 0;
}
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, int> pi;

const int MAX_N = 1e3 + 100, INF = 0x7fffffff;

int N, M;
vector<pi> Ed[MAX_N];
vector<pi> List[MAX_N];
vector<int> firstD;

int getDis(int x, int y)
{
	vector<int> Dis = vector<int>(N+1, INF);
	vector<bool> Chk = vector<bool>(N+1, false);
	priority_queue<pi, vector<pi>, greater<pi> > Q;
	Q.push(make_pair(0, 1)); Dis[1] = 0;

	while(!Q.empty())
	{
		int dis, now; tie(dis, now) = Q.top(); Q.pop();
		if(Chk[now]) continue;
		Chk[now] = true;
		for(auto &t : Ed[now])
		{
			int next = t.first, cost = t.second;
			if(now == x && next == y || next == x && now == y) continue;
			if(Dis[next] > Dis[now] + cost)
				Q.push( make_pair(Dis[next] = Dis[now] + cost, next) );
		}
	}
	if(x+y == 0) firstD = Dis;
	return Dis[N];
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int _=0; _<M; _++)
	{
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		Ed[x].push_back(make_pair(y, c));
		Ed[y].push_back(make_pair(x, c));
		List[x].push_back(make_pair(y, c));
	}
	int Just = getDis(0, 0);
	int MaxV = 0;
	for(int i=1; i<=N; i++)
	{
		for(auto &t : List[i])
		{
			if(firstD[i] + t.second == firstD[t.first] || firstD[t.first] + t.second == firstD[i])
			{
				int now = getDis(i, t.first);
				if(now == INF) {MaxV = INF; break;}
				MaxV = max(MaxV, now - Just);
			}
		}
	}
	if(MaxV == INF) MaxV = -1;
	printf("%d\n", MaxV);
	return 0;
}
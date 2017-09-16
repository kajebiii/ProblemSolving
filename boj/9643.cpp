#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

const int MAX_N = 2e3 + 100, INF = 0x7fffffff;

int N, D[MAX_N][MAX_N], SD[MAX_N][MAX_N];
vector<pi> Ed[MAX_N], List[MAX_N];
int Dis[MAX_N], Vst[MAX_N], Who[MAX_N];

void initGraph()
{
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) scanf("%d", &D[i][j]);
	for(int i=1; i<=N; i++) Dis[i] = INF, Vst[i] = 0, Who[i] = -1;
	Dis[1] = 0;
	int cnt = 0;
	while(1)
	{
		int v = -1;
		for(int i=1; i<=N; i++) if(Vst[i] == 0 && Dis[i] != INF)
			if(v == -1 || Dis[i] < Dis[v]) v = i;
		Vst[v] = 1;
		cnt++;		
		if(Who[v] != -1)
		{
			Ed[Who[v]].push_back(make_pair(v, Dis[v]));
			Ed[v].push_back(make_pair(Who[v], Dis[v]));
			List[v].push_back(make_pair(Who[v], Dis[v]));
		}
		if(cnt == N) break;
		for(int i=1; i<=N; i++) if(Dis[i] > D[v][i])
			Dis[i] = D[v][i], Who[i] = v;
	}
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++) Vst[j] = 0;
		queue<int> Q; Q.push(i); Vst[i] = 1; SD[i][i] = 0;
		while(!Q.empty())
		{
			int v = Q.front(); Q.pop();
			for(auto &w : Ed[v]) if(Vst[w.first] == 0)
			{
				Vst[w.first] = 1;
				SD[i][w.first] = SD[i][v] + w.second;
				Q.push(w.first);
			}
		}
	}
}
void delGraph()
{
	for(int i=1; i<=N; i++)
	{
		vector<pi> temp, temp2;
		Ed[i].swap(temp);
		List[i].swap(temp2);
	}
}
int main()
{
	bool first = true;
	while(scanf("%d", &N) == 1)
	{
		initGraph();
		int ans = INF, ix = -1, jx = -1;
		for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) if(SD[i][j] != D[i][j] && ans > D[i][j])
			ans = D[i][j], ix = i, jx = j;
		if(ans == INF) ans = D[ix=1][jx=2];
		List[ix].push_back(make_pair(jx, ans));
		if(!first) puts(""); else first = false;
		for(int i=1; i<=N; i++) for(auto &t : List[i]) printf("%d %d %d\n", i, t.first, t.second);
		delGraph();
	}
	return 0;
}
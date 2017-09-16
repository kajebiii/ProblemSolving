#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

const int MAX_N = 4e2 + 10;

struct ED
{
	int to, fl, co, re;
	ED(int to, int fl, int co, int re):to(to),fl(fl),co(co),re(re){}
};
int N, M, S, E, Nr[MAX_N][5];
vector<ED> Edge[MAX_N];
void addEdge(int fr, int to, int fl, int co)
{
	Edge[fr].push_back(ED(to, fl,  co, Edge[to].size()));
	Edge[to].push_back(ED(fr,  0, -co, Edge[fr].size()-1));
}
bool isBetween(int k, int x, int y)
{
	return (x <= k && k <= y) || (y <= k && k <= x);
}
void initGraph()
{
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N+M; i++) for(int j=0; j<5; j++) scanf("%d", &Nr[i][j]);
	for(int i=1; i<=N; i++) for(int j=N+1; j<=N+M; j++)
		if(isBetween(Nr[i][1], Nr[j][1], Nr[j][3]))
			if(isBetween(Nr[j][0], Nr[i][0], Nr[i][2]))
				addEdge(i, j, 1, Nr[i][4] * Nr[j][4]);
	S = 0, E = N+M+1;
	for(int i=1; i<=N; i++) addEdge(S, i, 1, 0);
	for(int j=N+1; j<=N+M; j++) addEdge(j, E, 1, 0);
}
void deleteGraph()
{
	for(int i=S; i<=E; i++)
	{
		vector<ED> temp;
		Edge[i].swap(temp);
	}
}
int Dis[MAX_N], inQ[MAX_N], Wh[MAX_N], Ix[MAX_N];
bool spfa()
{
	queue<int> Q;
	for(int i=S; i<=E; i++) Dis[i] = -1e9, inQ[i] = 0;
	Q.push(S); Dis[S] = 0; inQ[S] = 1;
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop(); inQ[v] = 0;
		for(int i=0; i<Edge[v].size(); i++)
		{
			ED &ed = Edge[v][i];
			if(ed.fl > 0 && Dis[ed.to] < Dis[v] + ed.co)
			{
				Dis[ed.to] = Dis[v] + ed.co;
				Wh[ed.to] = v;
				Ix[ed.to] = i;
				if(inQ[ed.to] == 0) inQ[ed.to] = 1, Q.push(ed.to);
			}
		}
	}
	return Dis[E] != -1e9;
}
int main()
{
	int tc; scanf("%d", &tc);
	for(int t=1; t<=tc; t++)
	{
		initGraph();
		int flow = 0, cost = 0;
		while(spfa())
		{
			int nowf = 0x7fffffff;
			for(int i=E; i!=S; i=Wh[i])
			{
				int v = Wh[i], w = i, ix = Ix[w];
				nowf = min(nowf, Edge[v][ix].fl);
			}
			for(int i=E; i!=S; i=Wh[i])
			{
				int v = Wh[i], w = i, ix = Ix[w], r = Edge[v][ix].re;
				Edge[v][ix].fl -= nowf;
				Edge[w][r ].fl += nowf;
			}
			flow += nowf;
			cost += nowf * Dis[E];
		}
		printf("%d %d\n", flow, cost);
		deleteGraph();
	}
	return 0;
}
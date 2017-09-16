#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1e3 + 10;

struct ED
{
	int to, fl, co, re;
	ED(int to, int fl, int co, int re):to(to),fl(fl),co(co),re(re){}
};
int N, Nr[MAX_N][2], S, E;
vector<ED> Edge[MAX_N + 100];
void addEdge(int fr, int to, int fl, int co)
{
	Edge[fr].push_back(ED(to, fl,  co, Edge[to].size()));
	Edge[to].push_back(ED(fr,  0, -co, Edge[fr].size()-1));
}
void initGraph()
{
	while(scanf("%d%d", &Nr[N+1][0], &Nr[N+1][1]) == 2) N++;
	for(int i=1; i<=N; i++)
	{
		addEdge(0, i, 1, 0);
		addEdge(i, N+1, 1, Nr[i][0]);
		addEdge(i, N+2, 1, Nr[i][1]);
	}
	addEdge(N+1, N+3, 15, 0);
	addEdge(N+2, N+3, 15, 0);
	S = 0, E = N+3;
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
	printf("%d\n", cost);
	return 0;
}
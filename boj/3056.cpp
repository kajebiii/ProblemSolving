#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

typedef long double ld;
const int MAX_N = 4e1 + 10;

struct ED
{
	int to, fl, re; ld co;
	ED(int to, int fl, ld co, int re):to(to),fl(fl),co(co),re(re){}
};
int N, S, E;
vector<ED> Edge[MAX_N];
void addEdge(int fr, int to, int fl, ld co)
{
	Edge[fr].push_back(ED(to, fl,  co, Edge[to].size()));
	Edge[to].push_back(ED(fr,  0, -co, Edge[fr].size()-1));
}
void initGraph()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
	{
		int x; scanf("%d", &x);
		ld cost = -5000;
		if(x != 0) cost = log((ld)x/100);
		addEdge(i, N+j, 1, cost);
	}
	S = 0, E = 2*N+1;
	for(int i=1; i<=N; i++)
	{
		addEdge(S, i, 1, 0);
		addEdge(i+N, E, 1, 0);
	}
}
ld Dis[MAX_N];
int inQ[MAX_N], Wh[MAX_N], Ix[MAX_N];
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
	int flow = 0; ld cost = 0;
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
		cost += Dis[E];
	}
	printf("%.11Lf\n", (ld)1*exp(cost)*100 );
	return 0;
}
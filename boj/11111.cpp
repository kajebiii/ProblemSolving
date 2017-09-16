#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

const int MAX_N = 2500 + 10;

struct ED
{
	int to, fl, co, re;
	ED(int to, int fl, int co, int re):to(to),fl(fl),co(co),re(re){}
};
int N, M, S, E; char Mp[55][55];
vector<ED> Edge[MAX_N];
void addEdge(int fr, int to, int fl, int co)
{
	Edge[fr].push_back(ED(to, fl,  co, Edge[to].size()));
	Edge[to].push_back(ED(fr,  0, -co, Edge[fr].size()-1));
}
int Cx[4]={-1,0,1,0}, Cy[4]={0,-1,0,1};
int Sc[6][6]={
	{10, 8, 7, 5, 0, 1},
	{ 8, 6, 4, 3, 0, 1},
	{ 7, 4, 3, 2, 0, 1},
	{ 5, 3, 2, 2, 0, 1},
	{ 0, 0, 0, 0, 0, 0},
	{ 1, 1, 1, 1, 0, 0}
};
int ch(int i, int j)
{
	return (i-1)*M + j;
}
void initGraph()
{
	scanf("%d%d", &N, &M);
	S = 0, E = N*M+1;
	for(int i=1; i<=N; i++) scanf("%s", Mp[i]+1);
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
	{
		if((i+j) % 2 == 1)
		{
			for(int k=0; k<4; k++)
			{
				int x = i+Cx[k], y=j+Cy[k];
				if(Mp[x][y]==0) continue;
				addEdge(ch(i, j), ch(x, y), 1, Sc[Mp[i][j]-'A'][Mp[x][y]-'A']);
			}
			addEdge(S, ch(i, j), 1, 0);
		}
		else
			addEdge(ch(i, j), E, 1, 0);
	}
	addEdge(E, E+1, N*M, 0);
	addEdge(S, E, N*M, 0);
	E++;
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
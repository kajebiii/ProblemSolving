#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_V = 333;

struct ED
{
	int to, fl, co, re;
	ED(int t, int f, int c, int r):to(t),fl(f),co(c),re(r){}
};
int N, M, St, En;
vector<ED> Ed[MAX_V];
void addEdge(int fr, int to, int fl, int co)
{
	Ed[fr].push_back(ED(to, fl, +co, Ed[to].size()));
	Ed[to].push_back(ED(fr,  0, -co, Ed[fr].size()-1));
}

void initGraph()
{
	scanf("%d%d", &N, &M);
	St = 0, En = N+M+1;
	for(int i=1, x; i<=N; i++) scanf("%d", &x), addEdge(i+M, En, x, 0);
	for(int i=1; i<=M; i++)
	{
		int c[5]; for(int j=0; j<5; j++) scanf("%d", &c[j]);
		for(int j=1; j<=4; j++)
			addEdge(i, c[j]+M+1, 1, -(c[0]*4+1-j) );
		addEdge(St, i, 1, 0);
	}
}
void deleteGraph()
{
	for(int i=St; i<=En; i++)
	{
		vector<ED> temp;
		Ed[i].swap(temp);
	}
}
int Dis[MAX_V], Wh[MAX_V], Ix[MAX_V]; bool inQ[MAX_V];
bool spfa()
{
	for(int i=St; i<=En; i++) Dis[i] = 1e9, inQ[i] = false;
	queue<int> Q; Q.push(St); Dis[St] = 0, inQ[St] = true;
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop(); inQ[v] = false;
		for(int i=0; i<Ed[v].size(); i++)
		{
			ED &e = Ed[v][i];
			if(e.fl > 0 && Dis[e.to] > Dis[v] + e.co)
			{
				Dis[e.to] = Dis[v] + e.co;
				Wh[e.to] = v; Ix[e.to] = i;
				if(inQ[e.to] == false) inQ[e.to] = true, Q.push(e.to);
			}
		}
	}
	return Dis[En] != 1e9;
}
int main()
{
	while(1)
	{
		initGraph();
		if(N == 0 && M == 0) break;
		int flow = 0, cost = 0;
		while(spfa())
		{
			int minF = 1e9;
			for(int w=En, i, v, r; w!=St; w=v)
			{
				v=Wh[w], i=Ix[w], r=Ed[v][i].re;
				minF = min(minF, Ed[v][i].fl);
			}
			for(int w=En, i, v, r; w!=St; w=v)
			{
				v=Wh[w], i=Ix[w], r=Ed[v][i].re;
				Ed[v][i].fl -= minF;
				Ed[w][r].fl += minF;
			}
			flow += minF;
			cost += minF * Dis[En];
		}
		printf("%d\n", -cost);
		deleteGraph();
	}
	return 0;
}
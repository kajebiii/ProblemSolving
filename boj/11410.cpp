#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_V = 55 * 2;

struct ED
{
	int to, fl, co, re;
	ED(int t, int f, int c, int r):to(t),fl(f),co(c),re(r){}
};
int St, En;
vector<ED> Ed[MAX_V];
void addEdge(int fr, int to, int fl, int co)
{
	Ed[fr].push_back(ED(to, fl, +co, Ed[to].size()));
	Ed[to].push_back(ED(fr,  0, -co, Ed[fr].size()-1));
}

int N, P, F[MAX_V/2][MAX_V/2];
void initGraph()
{
	scanf("%d%d", &N, &P);
	St = 0, En = 2*N + 1;
	addEdge(St, 1, P, 0);
	addEdge(N, En, P, 0);
	for(int i=1; i<=N; i++)
	{
		if(i != N) addEdge(i, i+1, P, 0);
		addEdge(i+N, i, P, 0);
	}
	for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++) scanf("%d", &F[i][j]);
	for(int i=1; i<=N; i++) for(int j=i+1, x; j<=N; j++)
	{
		scanf("%d", &x);
		addEdge(i, j+N, F[i][j], -x);
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
		break;
	}
	return 0;
}
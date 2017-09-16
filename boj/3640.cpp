#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_V = (1e3 + 10) * 2;

struct ED
{
	int to, fl, co, re;
	ED(int t_, int f_, int c_, int r_):to(t_),fl(f_),co(c_),re(r_){}
};
int V, E, St, En;
vector<ED> Ed[MAX_V];
void addEdge(int fr, int to, int fl, int co)
{
	Ed[fr].push_back(ED(to,  fl, +co, Ed[to].size()));
	Ed[to].push_back(ED(fr,   0, -co, Ed[fr].size()-1));
}

void initGraph()
{
	St = 0, En = V*2 + 1;
	addEdge(St, 1*2, 2, 0);
	addEdge(V*2-1, En, 2, 0);
	for(int i=1; i<=V; i++)
		addEdge(i*2-1, i*2, 1, 0);
	for(int _=0; _<E; _++)
	{
		int fr, to, co, fl = 1;
		scanf("%d%d%d", &fr, &to, &co);
		addEdge(fr*2, to*2-1, 1, co);
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
int Dis[MAX_V], Ix[MAX_V], Wh[MAX_V]; bool inQ[MAX_V];
bool spfa()
{
	queue<int> Q;
	for(int i=St; i<=En; i++) Dis[i] = 1e9, inQ[i] = false;
	Q.push(St); Dis[St] = 0, inQ[St] = true;
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		inQ[v] = false;
		for(int i=0; i<Ed[v].size(); i++)
		{
			ED &e = Ed[v][i];
			if(e.fl > 0 && Dis[e.to] > Dis[v] + e.co)
			{
				Dis[e.to] = Dis[v] + e.co;
				Wh[e.to] = v; Ix[e.to] = i;
				if(!inQ[e.to]) Q.push(e.to), inQ[e.to] = true;
			}
		}
	}
	return Dis[En] != 1e9;
}
int main()
{
	while(scanf("%d%d", &V, &E) == 2)
	{
		initGraph();
		int flow = 0, cost = 0;
		while(spfa())
		{
			int nowF = 1e9;
			for(int w=En, v, i; w!=St; w=v)
			{
				v=Wh[w],i=Ix[w];
				nowF = min(nowF, Ed[v][i].fl);
			}
			for(int w=En, v, i, r; w!=St; w=v)
			{
				v=Wh[w], i=Ix[w], r=Ed[v][i].re;
				Ed[v][i].fl -= nowF, Ed[w][r].fl += nowF;
			}
			flow += nowF;
			cost += Dis[En] * nowF;
		}
		deleteGraph();
		printf("%d\n", cost);
	}
	return 0;
}
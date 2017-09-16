#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct ED
{
	int to, fl, co, re;
	ED(int t, int f, int c, int r):to(t),fl(f),co(c),re(r){}
};
const int MAX_N = 20 * 2, INF = 0x7fffffff, BIG = 20000;
typedef long long ll;
vector<ED> Edge[MAX_N];
void addEdge(int fr, int to, int fl, int co)
{
	Edge[fr].push_back(ED(to, fl,  co, Edge[to].size()));
	Edge[to].push_back(ED(fr,  0, -co, Edge[fr].size()-1));
}
int N, maxF, S, E; ll baseCost;
int C[MAX_N][MAX_N], D[MAX_N][MAX_N];
int In[MAX_N], Out[MAX_N];
void makeGraph()
{
	scanf("%d%d", &N, &maxF);
	S = 0, E = 2*N+1;
	for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++) scanf("%d", &C[i][j]);
	for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++) scanf("%d", &D[i][j]);
	
	baseCost = 0;
	for(int i=1; i<=N; i++) for(int j=i+1, x; j<=N; j++)
		scanf("%d", &x), addEdge(i, j+N, x, BIG), baseCost += 1ll * x * BIG;
	addEdge(S, 1, maxF, 0);
	for(int i=1; i<=N; i++) addEdge(i+N, E, maxF, 0);
	for(int i=1; i<=N; i++) addEdge(i+N, i, maxF, 0);
	for(int i=1; i< N; i++) addEdge(i, i+1, maxF, 0);
	for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++)
		addEdge(i, j+N, D[i][j], C[i][j]);
	/*
	for(int i=1; i<=N; i++) In[i] = Out[i] = maxF;
	for(int i=1; i<=N; i++) for(int j=i+1, x; j<=N; j++) 
		scanf("%d", &x), In[i] -= x, Out[j] -= x;
	for(int i=1; i<=N; i++) addEdge(S, i, In[i], 0);
	for(int i=1; i<=N; i++) addEdge(i+N, E, Out[i], 0);
	for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++)
		addEdge(i, j+N, D[i][j], C[i][j]);
	*/
}
void deleteGraph()
{
	for(int i=S; i<=E; i++)
	{
		vector<ED> temp;
		Edge[i].swap(temp);
	}
}

int Dis[MAX_N], inQ[MAX_N], From[MAX_N], Ix[MAX_N];
bool spfa()
{
	for(int i=S; i<=E; i++) Dis[i] = -1e9, inQ[i] = 0, From[i] = 0, Ix[i] = 0;
	queue<int> Q; Dis[0] = 0; Q.push(0); inQ[0] = 1;
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		inQ[v] = 0;
		for(int i=0; i<Edge[v].size(); i++)
		{
			ED &ed = Edge[v][i]; int w = ed.to;
			if(ed.fl > 0 && Dis[w] < Dis[v] + ed.co)
			{
				Dis[w] = Dis[v] + ed.co;
				From[w] = v;
				Ix[w] = i;
				if(inQ[w] == 0) inQ[w] = 1, Q.push(w);
			}
		}
	}
	return Dis[E] > -1e9;
}
int main()
{
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		makeGraph();
		int flow = 0;
		ll cost = 0;
		while(spfa())
		{
			int minF = INF;
			for(int w=E; w!=S; w=From[w]) minF = min(minF, Edge[From[w]][Ix[w]].fl);
			for(int w=E; w!=S; w=From[w])
			{
				int v = From[w], i = Ix[w], r = Edge[v][i].re;
				Edge[v][i].fl -= minF;
				Edge[w][r].fl += minF;
			}
			cost += 1ll * Dis[E] * minF;
			flow += minF;
		}
		printf("%lld\n", cost - baseCost);
		deleteGraph();
	}
	return 0;
}
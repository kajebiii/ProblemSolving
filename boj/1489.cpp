#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

struct ED
{
	int to, fl, re, co;
	ED(int t, int f, int r, int c):to(t), fl(f), re(r), co(c){}
};

const int MAX_N = 2e3 + 100;

vector<ED> Edge[MAX_N];
void addEdge(int fr, int to, int fl, int co)
{
	Edge[fr].push_back(ED(to, fl, Edge[to].size()  ,  co));
	Edge[to].push_back(ED(fr,  0, Edge[fr].size()-1, -co));
}

int Dis[MAX_N], inQ[MAX_N], from[MAX_N], Ix[MAX_N], S, E;
bool spfa()
{
	for(int i=S; i<=E; i++) Dis[i] = -1e9, inQ[i] = from[i] = Ix[i] = 0;
	queue<int> Q;
	Dis[S] = 0; Q.push(S); inQ[S] = 1;
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		inQ[v] = 0;
		int ix = 0;
		for(ED &ed : Edge[v])
		{
			if(ed.fl > 0 && Dis[ed.to] < Dis[v] + ed.co)
			{
				Dis[ed.to] = Dis[v] + ed.co;
				from[ed.to] = v;
				Ix[ed.to] = ix;
				if(inQ[ed.to] == 0) inQ[ed.to] = 1, Q.push(ed.to);
			}
			ix++;
		}
	}
	return Dis[E] > -1e9;
}
int Nr[MAX_N], N;
int main()
{
	scanf("%d", &N); S = 0; E = 2*N+1;
	for(int i=1; i<=2*N; i++) scanf("%d", &Nr[i]);
	for(int i=1; i<=N; i++) for(int j=N+1; j<=2*N; j++)
			addEdge(i, j, 1, (Nr[i] == Nr[j]) + 2 * (Nr[i] > Nr[j]));
	for(int i=1; i<=N; i++) addEdge(0, i, 1, 0);
	for(int i=N+1; i<=2*N; i++) addEdge(i, E, 1, 0);
	int flow = 0, sum = 0;
	while(spfa())
	{
		flow++;
		sum += Dis[E];
		for(int i=E; i!=S; i=from[i]) 
		{
			int ix = Ix[i], re = Edge[from[i]][ix].re;
			Edge[from[i]][ix].fl--;
			Edge[i][re].fl++;
		}
	}
	printf("%d\n", sum);
	return 0;
}
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 500, MAX_Q = 500, MAX_S = 1500, MAX_V = 4e3, INF = 0x7fffffff;

struct ED
{
	int to, fl, re;
	ED(int t, int f, int r) : to(t), fl(f), re(r) {}
};

int N, Q, S, mQ[MAX_Q], mS[MAX_S];
int St, En, Sum;

vector<ED> Ed[MAX_V];
void addEdge(int fr, int to, int fl)
{
	Ed[fr].push_back(ED(to,fl,Ed[to].size()));
	Ed[to].push_back(ED(fr,0,Ed[fr].size()-1));
}
void initGraph()
{
	scanf("%d%d%d", &N, &Q, &S);
	for(int i=1; i<=S; i++) scanf("%d", &mS[i]);
	for(int i=1; i<=Q; i++) scanf("%d", &mQ[i]);

	St = 0; En = (2*Q+1) * N + 1;
	for(int p=0; p<N; p++)
	{
		int end = p*(2*Q+1)+2*Q+1;

		int d; scanf("%d", &d);
		for(int i=1; i<=S; i++)
		{
			int x; scanf("%d", &x);
			Sum += x;
			addEdge(St, p*(2*Q+1)+mS[i]*2-1, x);
		}
		for(int i=1; i<=Q; i++)
		{
			addEdge(p*(2*Q+1)+i*2-1, p*(2*Q+1)+i*2, mQ[i]);
			addEdge(p*(2*Q+1)+i*2, end, INF);
		}
		addEdge(end, En, d);
	}
	for(int p=1; p<N; p++)
		for(int i=1; i<=Q; i++)
			addEdge((p-1)*(2*Q+1)+i*2, p*(2*Q+1)+i*2-1, mQ[i]);
	return;
}

int Lv[MAX_V], ix[MAX_V];
bool bfs()
{
	for(int i=St; i<=En; i++) Lv[i] = 0;
	queue<int> Q; Q.push(St); Lv[St] = 1;

	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		for(ED &l : Ed[v])
		{
			if(l.fl > 0 && Lv[l.to] == 0)
			{
				Q.push(l.to); Lv[l.to] = Lv[v] + 1;
				if(l.to == En) return true;
			}
		}
	}
	return false;
}
int dfs(int v, int minf)
{
	if(v == En) return minf;
	for(int &i = ix[v], m; i<Ed[v].size(); i++)
	{
		ED &l = Ed[v][i];
		if(Lv[l.to] > Lv[v] && l.fl > 0)
		{
			(m = dfs(l.to, min(minf, l.fl)));
			if(m == 0) continue;
			l.fl -= m;
			Ed[l.to][l.re].fl += m;
			return m;
		}
	}
	return 0;
}
int main()
{
	initGraph();
	int flow = 0;
	while(bfs())
	{
		for(int i=St; i<=En; i++) ix[i] = 0;
		for(int f; (f=dfs(St,INF)) != 0; flow += f);
	}
	if(flow == Sum) puts("possible");
	else puts("impossible");
	return 0;
}
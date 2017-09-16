#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_V = 25e2 + 200, MAX_N = 5e1 + 10, INF = 0x7fffffff;

struct ED
{
	int to, fl, re;
	ED(int t, int f, int r) : to(t), fl(f), re(r) {}
};

int N, M, Nr[MAX_N][MAX_N];
vector<ED> Ed[MAX_V];

void addEdge(int fr, int to, int fl)
{
	Ed[fr].push_back(ED(to, fl, Ed[to].size()	));
	Ed[to].push_back(ED(fr, 0,  Ed[fr].size()-1	));
}

int S, E;
void initGraph()
{
	scanf("%d%d", &N, &M);
	S = 0; E = N*M + 1;
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) scanf("%d", &Nr[i][j]);
	for(int i=0; i<N; i++) for(int j=0; j<M; j++)
		if( (i+j) % 2 == 0 ) 
			addEdge(S, i*M+j + 1, Nr[i][j]);
		else
			addEdge(i*M+j + 1, E, Nr[i][j]);

	for(int i=0; i<N; i++) for(int j=0; j<M; j++)
	{
		int v = i*M+j+1;
		int ch[2][2] = { {1, 0}, {0, 1} };
		for(int k=0; k<2; k++)
		{
			int x = i + ch[k][0], y = j + ch[k][1];
			if(x>=N || y>=M) continue;
			int w = x*M+y+1;
			if( (i+j) % 2 == 0)
				addEdge(v, w, INF);
			else
				addEdge(w, v, INF);
		}
	}
}
void delGraph()
{
	for(int i=S; i<=E; i++)
	{
		vector<ED> temp;
		Ed[i].swap(temp);
	}
}

int Lv[MAX_V], Ix[MAX_V];
bool bfs()
{
	for(int i=S; i<=E; i++) Lv[i] = -1;
	queue<int> Q; Q.push(S); Lv[S] = 0;
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		for(auto &e : Ed[v])
			if(Lv[e.to] == -1 && e.fl != 0)
			{
				Lv[e.to] = Lv[v] + 1;
				Q.push(e.to);
				if(e.to == E) return true;
			}
	}
	return false;
}
int dfs(int v, int f)
{
	if(v == E) return f;
	for(int &i = Ix[v], nf; i<Ed[v].size(); i++)
	{
		auto &e = Ed[v][i];
		if(Lv[e.to] > Lv[v] && e.fl > 0 && (nf = dfs(e.to, min(f, e.fl))) > 0)
		{
			e.fl -= nf;
			Ed[e.to][e.re].fl += nf;
			return nf;
		}
	}
	return 0;
}

int main()
{
	int tc; scanf("%d", &tc);
	for(int t=0; t<tc; t++)
	{
		initGraph();
		int flow = 0, sum = 0;
		for(int i=0; i<N; i++) for(int j=0; j<M; j++) sum += Nr[i][j];
		for(int f; bfs(); )
		{
			for(int i=S; i<=E; i++) Ix[i] = 0;
			while( (f = dfs(S, INF) ) > 0 ) flow += f;
		}
		printf("%d\n", sum - flow);
		delGraph();
	}

	return 0;
}

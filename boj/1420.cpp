#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct ED
{
	int t, f, r;
	ED(int t_, int f_, int r_) : t(t_), f(f_), r(r_) {}
};
const int MAX_V = 100 * 100 * 2 + 200, MAX_N = 1e2 + 10, INF = 0x3fffffff;
vector<ED> Ed[MAX_V];
void addEdge(int fr, int to, int fl)
{
	Ed[fr].push_back(ED(to, fl, Ed[to].size()));
	Ed[to].push_back(ED(fr,  0, Ed[fr].size()-1));
}
int N, M, S, E, St, En;
int node(int n, int m, int in) // 0 : in , 1 : out ?
{
	int nr = n*M + m + 1;
	return nr*2 + in;
}
char Mp[MAX_N][MAX_N];

int lv[MAX_V], ix[MAX_V];
bool bfs()
{
	for(int i=S; i<=E; i++) lv[i] = -1;
	queue<int> Q; Q.push(S); lv[S] = 0;
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		for(auto &e : Ed[v])
			if(lv[e.t] == -1 && e.f > 0)
			{
				lv[e.t] = lv[v] + 1;
				if(e.t == E) return true;
				Q.push(e.t);
			}
	}
	return false;
}

int dfs(int v, int f)
{
	if(v == E) return f;
	for(int &i=ix[v], nf; i<Ed[v].size(); i++)
	{
		auto &e = Ed[v][i];
		if(lv[e.t] > lv[v] && e.f > 0 && (nf = dfs(e.t, min(e.f, f))) > 0)
		{
			e.f -= nf;
			Ed[e.t][e.r].f += nf;
			return nf;
		}
	}
	return 0;
}


int main()
{
	[&]() // input
	{
		scanf("%d%d", &N, &M);
		for(int i=0; i<N; i++) scanf("%s", Mp[i]);
		for(int i=0; i<N; i++) for(int j=0; j<M; j++)
			if(Mp[i][j] == 'K') 
				St = node(i, j, 1);
			else if(Mp[i][j] == 'H') 
				En = node(i, j, 0);

		S = 0, E = node(N, 0, 0);
		addEdge(S, St, INF), addEdge(En, E, INF);
		for(int i=0; i<N; i++) for(int j=0; j<M; j++)
			if(Mp[i][j] != '#')
				addEdge(node(i, j, 0), node(i, j, 1), 1);
		for(int i=0; i<N; i++) for(int j=0; j<M; j++)
		{
			if(Mp[i][j] == '#') continue;
			for(int k=0; k<2; k++)
			{
				int x = i + "01"[k] - '0';
				int y = j + "10"[k] - '0';
				if(x >= N || y >= M) continue;
				if(Mp[x][y] == '#') continue;
				addEdge(node(i, j, 1), node(x, y, 0), INF);
				addEdge(node(x, y, 1), node(i, j, 0), INF);
			}
		}
	}();

	int flow = 0;
	while(bfs())
	{
		for(int i=S; i<=E; i++) ix[i] = 0;
		for(int f; (f=dfs(S, INF)) > 0; flow += f);
	}
	if(flow >= INF) flow = -1;
	printf("%d\n", flow);

	return 0;
}
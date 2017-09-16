#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct ED
{
	int to, co, re;
	ED(int t, int c, int r) : to(t), co(c), re(r) {}
};

const int MAX_N = 444 * 2, INF = 0x7fffffff;

int N, M, S = 1 * 2 - 1, E = 2 * 2;
vector<ED> V[MAX_N];
void addEdge(int t, int w, int c)
{
	V[t].push_back(ED(w, c, V[w].size()));
	V[w].push_back(ED(t, 0, V[t].size()-1));
}

int Lv[MAX_N];
bool bfs()
{
	for(int i=1; i<=N*2; i++) Lv[i] = 0;
	queue<int> Q; Q.push(S); Lv[S] = 1;
	while(!Q.empty())
	{
		int now = Q.front(); Q.pop();
		for(auto &temp : V[now])
			if(temp.co != 0 && Lv[temp.to] == 0)
			{
				Lv[temp.to] = Lv[now] + 1;
				Q.push(temp.to);
				if(temp.to == E) return true;
			}
	}
	return false;
}

int Ix[MAX_N];
int dfs(int v, int f)
{
	if(v == E) return f;
	for(int &i = Ix[v]; i < V[v].size(); i++)
	{
		auto &temp = V[v][i];
		if(Lv[temp.to] > Lv[v] && temp.co != 0)
		{
			int m = dfs(temp.to, min(f, temp.co));
			if(m == 0) continue;
			temp.co -= m;
			V[temp.to][temp.re].co += m;
			return m;
		}
	}
	return 0;
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0, x, y; i<M; i++)
		scanf("%d%d", &x, &y), addEdge(x*2-1, y*2, 1), addEdge(y*2-1, x*2, 1);
	for(int i=1; i<=N; i++) addEdge(i*2-1, i*2, 1), addEdge(i*2, i*2-1, 1);

	int flow = 0;
	while(true)
	{
		if(!bfs()) break;
		int f = 0;
		for(int i=1; i<=N*2; i++) Ix[i] = 0;
		while((f = dfs(S, INF)) != 0) flow += f;
	}

	printf("%d\n", flow);
	return 0;
}
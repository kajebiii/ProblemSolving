#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 2e2 + 10, INF = 0x7fffffff;

int N, M, S, E;
struct EG
{
	int to, fl, re;
	EG():to(0), fl(0), re(0){}
	EG(int t, int f, int r):to(t), fl(f), re(r){}
};
vector<EG> Edge[MAX_N];

void addEdge(int fr, int to, int fl)
{
	Edge[fr].push_back(EG(to, fl, Edge[to].size()));
	Edge[to].push_back(EG(fr,  0, Edge[fr].size()-1));
}

int Lv[MAX_N], Ix[MAX_N];
bool bfs()
{
	for(int i=S; i<=E; i++) Lv[i] = 0;
	queue<int> Q; Q.push(S); Lv[S] = 1;
	while(!Q.empty())
	{
		int now = Q.front(); Q.pop();
		for(EG &eg : Edge[now])
			if(eg.fl > 0 && Lv[eg.to] == 0)
			{
				Lv[eg.to] = Lv[now] + 1;
				Q.push(eg.to);
				if(eg.to == E) return true;
			}
	}
	return false;
}
int dfs(int v, int f)
{
	if(v == E) return f;
	for(int &i = Ix[v]; i<Edge[v].size(); i++)
	{
		EG &eg = Edge[v][i];
		if(Lv[eg.to] > Lv[v] && eg.fl > 0)
		{
			int value = dfs(eg.to, min(f, eg.fl));
			if(value == 0) continue;
			eg.fl -= value;
			Edge[eg.to][eg.re].fl += value;
			return value;
		}
	}
	return 0;
}
int main()
{
	scanf("%d%d", &N, &M);
	S = 0, E = N + M + 1;
	for(int i=1, x; i<=N; i++) scanf("%d", &x), addEdge(S  ,i, x);
	for(int i=1, x; i<=M; i++) scanf("%d", &x), addEdge(N+i,E, x);
	for(int j=N+1, f; j<=N+M; j++) for(int i=1; i<=N; i++)
		scanf("%d", &f), addEdge(i, j, f);
	
	int flow = 0;
	while(1)
	{
		if(!bfs()) break;
		for(int i=S; i<=E; i++) Ix[i] = 0;
		for(int f=0; (f = dfs(S, INF)) != 0; flow += f);
	}
	printf("%d\n", flow);
	return 0;
}
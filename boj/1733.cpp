#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1e6 + 100, INF = 0x7fffffff;

int N, MatchA[MAX_N], MatchB[MAX_N];
int Lv[MAX_N];
vector<int> Edge[MAX_N];

void bfs()
{
	queue<int> Q;
	for(int i=1; i<=N; i++) if(MatchA[i] == 0)
	{
		Lv[i] = 0;
		Q.push(i);
	}else Lv[i] = INF;
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		for(int w : Edge[v])
			if(MatchB[w] != 0 && Lv[MatchB[w]] == INF)
				Lv[MatchB[w]] = Lv[v] + 1, Q.push(MatchB[w]);
	}
}

bool dfs(int v)
{
	for(int w : Edge[v])
		if(MatchB[w] == 0 || (Lv[MatchB[w]] > Lv[v] && dfs(MatchB[w])))
		{
			MatchB[w] = v;
			MatchA[v] = w;
			return true;
		}
	return false;
}
int main()
{
	scanf("%d", &N);
	for(int i=1, x, y; i<=N; i++)
		scanf("%d%d", &x, &y), Edge[i].push_back(x), Edge[i].push_back(y);
	int flow = 0;
	while(1)
	{
		bfs();
		int f = 0;
		for(int i=1; i<=N; i++) if(MatchA[i] == 0 && dfs(i)) f++;
		flow += f;
		if(f == 0) break;
	}
	if(flow != N) printf("-1\n");
	else for(int i=1; i<=N; i++) printf("%d\n", MatchA[i]);
	return 0;
}
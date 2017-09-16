#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1e3 + 100;

int N, M;
vector<int> Ed[MAX_N];

void initGraph()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i<M; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		Ed[x].push_back(y);
	}
}
void delGraph()
{
	for(int i=0; i<N; i++)
	{
		vector<int> temp;
		Ed[i].swap(temp);
	}
}

int ma[MAX_N], mb[MAX_N], lv[MAX_N];
void bfs()
{
	queue<int> Q;
	for(int i=0; i<N; i++) lv[i] = -1;
	for(int i=0; i<N; i++) if(ma[i] == -1) Q.push(i), lv[i] = 0;
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		for(int w : Ed[v])
			if(mb[w] != -1 && lv[mb[w]] == -1)
			{
				lv[mb[w]] = lv[v] + 1;
				Q.push(mb[w]);
			}
	}
}
bool dfs(int v)
{
	for(int w : Ed[v])
		if(mb[w] == -1 || lv[mb[w]] > lv[v] && dfs(mb[w]))
		{
			mb[w] = v;
			ma[v] = w;
			return true;
		}
	return false;
}

int main()
{
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		initGraph();
		int flow = 0;
		for(int i=0; i<N; i++) ma[i] = mb[i] = -1;
		while(true)
		{
			bfs();
			int past = flow;
			for(int i=0; i<N; i++)
				if(ma[i] == -1 && dfs(i))
					flow++;
			if(past == flow) break;
		}
		printf("%d\n", flow);
		delGraph();
	}
	return 0;
}
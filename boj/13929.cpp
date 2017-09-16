#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int MAX_N = 1e5 + 100;

int N, M, Dy[MAX_N], Temp[MAX_N];
vector<int> Ed[MAX_N];

int D[MAX_N], DN, G[MAX_N], GN; stack<int> S;
vector<int> Gp[MAX_N];
int getLow(int v)
{
	int low; low = D[v] = ++DN; S.push(v);
	for(int w : Ed[v]) low = min(low, D[w]==0?getLow(w):G[w]==0?D[w]:low);
	if(low == D[v]) for(++GN; 1;)
	{
		int now = S.top(); S.pop();
		G[now] = GN;
		if(now == v) break;
	}
	return low;
}
void initGraph()
{
	scanf("%d%d", &N, &M);
	while(M--)
	{
		int x, y; scanf("%d%d", &x, &y);
		Ed[x].push_back(y);
	}
	for(int i=1; i<=N; i++) if(D[i] == 0) getLow(i);
	for(int i=1; i<=N; i++) Gp[G[i]].push_back(i);
}

vector<int> list;
int Find(int v)
{
	for(int i=0; i<list.size(); i++) if(list[i] == v) return i;
	printf("ERROR\n");
	return -1;
}
void updateG(int g)
{
	list = Gp[g];
	int Ch[10], n = list.size();
	int EdG[10][10] = {0};
	if(n > 6) {printf("ERROR\n"); return;}
	for(int i=0; i<n; i++) Ch[i] = i;
	for(int v : Gp[g]) for(int w : Ed[v]) 
		if(G[v] == G[w])
			EdG[Find(v)][Find(w)] = 1;
	do
	{
		int now = list[Ch[0]];
		for(int i=1; i<n; i++)
		{
			if(EdG[Ch[i-1]][Ch[i]] == 0) break;
			int to = list[Ch[i]];
			Temp[to] = max(Temp[to], Dy[now] + i);
		}
	}while(next_permutation(Ch, Ch+n));

	for(int v : list) Dy[v] = max(Dy[v], Temp[v]);
}
int main()
{
	initGraph();
	for(int i=1; i<=N; i++) Dy[i] = 1;
	for(int g=GN; g>=1; g--)
	{
		updateG(g);
		for(int v : Gp[g]) for(int w : Ed[v]) 
			if(G[v] != G[w])
				Dy[w] = max(Dy[w], Dy[v] + 1);
	}
	int ans = 0;
	for(int i=1; i<=N; i++) ans = max(ans, Dy[i]);
	printf("%d\n", ans);
	return 0;
}
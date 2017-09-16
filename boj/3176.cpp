#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

const int MAX_N = 1e5 + 100, LOG_N = 18, INF = 0x7fffffff;

int N;
vector<pi> Ed[MAX_N];

int D[MAX_N], P[MAX_N][LOG_N+1][3];
void dfs(int v, int p)
{
	P[v][0][0] = p;
	D[v] = D[p] + 1;
	for(auto &t : Ed[v])
		if(t.first != p)
		{
			P[t.first][0][1] = t.second;
			P[t.first][0][2] = -t.second;
			dfs(t.first, v);
		}
}
int glca(int a, int b)
{
	if(D[a] > D[b]) swap(a, b);
	for(int i=LOG_N; i>=0; i--) if((D[b]-D[a]) & (1<<i)) b = P[b][i][0];
	if(a == b) return a;
	for(int i=LOG_N; i>=0; i--)
		if(P[a][i][0] != P[b][i][0])
			a = P[a][i][0], b = P[b][i][0];
	return P[a][0][0];
}
int getMin(int x, int y, int k)
{
	if(D[x] > D[y]) swap(x, y);
	int res = INF;
	for(int i=LOG_N; i>=0; i--) if((D[y] - D[x]) & (1 << i))
	{
		res = min(res, P[y][i][k]);
		y = P[y][i][0];
	}
	return res;
}

int main()
{
	scanf("%d", &N); 
	for(int i=1, x, y, w; i<N; i++) 
		scanf("%d%d%d", &x, &y, &w), Ed[x].push_back(make_pair(y, w)), Ed[y].push_back(make_pair(x, w));
	P[1][0][1] = INF; P[1][0][2] = INF;
	dfs(1, 0);
	for(int p=1; p<=LOG_N; p++)
		for(int i=1; i<=N; i++)
		{
			P[i][p][0] = P[P[i][p-1][0]][p-1][0];
			P[i][p][1] = min(P[P[i][p-1][0]][p-1][1], P[i][p-1][1]);
			P[i][p][2] = min(P[P[i][p-1][0]][p-1][2], P[i][p-1][2]);
		}
	int Q; scanf("%d", &Q);
	for(int i=0; i<Q; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		int a = glca(x, y);
		for(int k=1; k<=2; k++)
			printf("%d ", (3-k*2) * min(getMin(x, a, k), getMin(y, a, k)));
		puts("");
	}
	return 0;
}
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e4 + 100;

int N;
vector<int> Ed[MAX_N];
int F[MAX_N][2], FN;

int dfs(int v, int p)
{
	int cnt = 0, size = 1;
	F[v][0] = ++FN;
	for(int w : Ed[v]) if(w != p)
	{
		if(cnt > 0) F[w][1] = F[v][1];
		else F[w][1] = F[v][0];
		cnt++;
		size += dfs(w, v);
	}
	if(size == 1)
	{
		F[v][0] = F[p][1];
		if(F[v][0] == F[v][1]) F[v][0] = ++FN;
	}
	return size;
}
int main()
{
	scanf("%d", &N);
	for(int i=1; i<N; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		Ed[x].push_back(y);
		Ed[y].push_back(x);
	}
	F[1][1] = ++FN;
	dfs(1, 0);
	for(int i=1; i<=N; i++) printf("%d %d\n", F[i][0], F[i][1]);
	return 0;
}
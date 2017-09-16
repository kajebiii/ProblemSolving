#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 5e2 + 10;

int N, M;
int Nr[MAX_N], Mp[MAX_N][MAX_N];
vector<int> Ed[MAX_N];

void initGraph()
{
	for(int i=1; i<=N; i++)
		scanf("%d", &Nr[i]);
	for(int i=0, x, y; i<M; i++)
	{
		scanf("%d%d", &x, &y);
		Mp[x][y] = Mp[y][x] = 1;
		Ed[x].push_back(y);
		Ed[y].push_back(x);
	}
}
void delGraph()
{
	for(int i=1; i<=N; i++) for(int j : Ed[i]) Mp[i][j] = 0;
	for(int i=1; i<=N; i++)
	{
		vector<int> temp;
		Ed[i].swap(temp);
	}
}
int main()
{
	while(scanf("%d%d", &N, &M) == 2)
	{
		initGraph();
		int ans = 0;
		for(int i=1; i<=N; i++) for(int j : Ed[i]) ans = max(ans, Nr[i] + Nr[j]);
		for(int i=1; i<=N; i++) for(int j : Ed[i]) for(int k : Ed[i])
			if(Mp[j][k] == 1) ans = max(ans, Nr[i] + Nr[j] + Nr[k]);
		for(int i=1; i<=N; i++) for(int j : Ed[i]) for(int k=i+1; k<=N; k++) for(int l : Ed[k])
			if(Mp[j][k] && Mp[j][l] && Mp[i][k] && Mp[i][l])
				ans = max(ans, Nr[i] + Nr[j] + Nr[k] + Nr[l]);
		printf("%d\n", ans);
		delGraph();
	}
	return 0;
}
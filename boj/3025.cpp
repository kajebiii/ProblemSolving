#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 3e4 + 100, MAX_M = 33;

int N, M, Q;
char Mp[MAX_N][MAX_M];
vector<int> Path[MAX_M];

void goPath(int k)
{
	int val = Path[k].back();
	int n = Path[k].size() - 1;
	Mp[n][val] = 'O';
	Path[k].erase(Path[k].begin() + n);
}
void update(int k)
{
	while(true)
	{
		int n = Path[k].size() - 1;
		int m = Path[k][n];
		if(Mp[n][m] == 'O')
		{
			Path[k].erase(Path[k].begin() + n);
			continue;
		}
		if(n == N) break;
		if(Mp[n+1][m] == '.')
		{
			Path[k].push_back(m);
			continue;
		}
		if(Mp[n+1][m] == 'X') break;
		if(Mp[n+1][m-1] == '.' && Mp[n][m-1] == '.')
		{
			Path[k].push_back(m-1);
			continue;
		}
		if(Mp[n+1][m+1] == '.' && Mp[n][m+1] == '.')
		{
			Path[k].push_back(m+1);
			continue;
		}
		break;
	}
}
int main()
{
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++) scanf("%s", Mp[i] + 1);
	for(int i=1; i<=M; i++) Path[i].push_back(0), Path[i].push_back(i);
	for(int i=1; i<=M; i++) update(i);
	scanf("%d", &Q);
	for(int q=0; q<Q; q++)
	{
		int m; scanf("%d", &m);
		goPath(m);
		for(int i=1; i<=M; i++) update(i);
	}
	for(int i=1; i<=N; i++) printf("%s\n", Mp[i]+1);
	return 0;
}
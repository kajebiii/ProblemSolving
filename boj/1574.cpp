#include <stdio.h>
#include <vector>

using namespace std;

const int MAX_N = 3e2 + 10;

int N, M, K, Chk[MAX_N][MAX_N];
vector<int> Edge[MAX_N];
bool Visit[MAX_N]; int Match[MAX_N];
bool findMatch(int v)
{
	if(Visit[v] == true) return false;
	Visit[v] = true;
	for(int w : Edge[v])
		if(Match[w] == 0 || findMatch(Match[w]))
		{
			Match[w] = v;
			return true;
		}
	return false;
}
int main()
{
	scanf("%d%d%d", &N, &M, &K);
	for(int k=0; k<K; k++)
	{
		int x, y; scanf("%d%d", &x, &y);
		Chk[x][y] = 1;
	}
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
		if(Chk[i][j] == 0) Edge[i].push_back(j);

	int ans = 0;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++) Visit[j] = false;
		if(findMatch(i)) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
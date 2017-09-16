#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
const int MAX_N = 1e3 + 100;
int N, M;
vector<int> V[MAX_N];
bool Visit[MAX_N];
int Match[MAX_N];

bool findMatch(int v)
{
	if(Visit[v] == true) return false;
	Visit[v] = true;
	for(int w : V[v])
		if(Match[w] == 0 || findMatch(Match[w]))
		{
			Match[w] = v;
			return true;
		}
	return false;
}

int main()
{
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d%d", &N, &M);
		for(int i=1, x, y; i<=M; i++)
		{
			scanf("%d%d", &x, &y);
			for(int j=x; j<=y; j++)
				V[j].push_back(i);
		}

		int ans = 0;
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++) Visit[j] = false;
			if(findMatch(i)) ans++;
		}
		printf("%d\n", ans);

		for(int i=1; i<=M; i++) Match[i] = 0;
		for(int i=1; i<=N; i++)
		{
			vector<int> temp;
			V[i].swap(temp);
		}
	}
}
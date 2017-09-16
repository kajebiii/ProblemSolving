#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e2 + 10;

bool Visit[MAX_N];
int N, M, Match[MAX_N];
vector<int> Edge[MAX_N];
bool findMatch(int v)
{
	if(Visit[v] == true) return false;
	Visit[v] = true;
	for(int w : Edge[v])
		if(Match[w] == -1 || findMatch(Match[w]))
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
		for(int i=1; i<=M; i++)
		{
			int t[2]; for(int k=0; k<2; k++) scanf("%d", &t[k]);
			int o; scanf("%d", &o);
			for(int j=0, x; j<o; j++)
			{
				scanf("%d", &x);
				for(int k=t[0]; k<t[1]; k++)
					Edge[x].push_back(k);
			}
		}
		for(int i=0; i<MAX_N; i++) Match[i] = -1;
		int ans = -1, match = 0;
		for(int i=1; i<=N; i++) sort(Edge[i].begin(), Edge[i].end());
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++) Visit[j] = false;
			if(findMatch(i)) match++;
		}
		for(int i=0; i<MAX_N; i++) if(Match[i] != -1) ans = i;
		if(match == N) printf("%d\n", ans+1); else puts("-1");
		for(int i=1; i<=N; i++)
		{
			vector<int> temp;
			Edge[i].swap(temp);
		}
	}
	return 0;
}
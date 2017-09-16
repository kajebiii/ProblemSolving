#include <stdio.h>
#include <vector>

using namespace std;

const int MAX_N = 1e4 + 100;
int N, M, Chk;
vector<int> Edge[MAX_N];
int Visit[MAX_N], Match[MAX_N];
bool findMatch(int v)
{
	if(Visit[v] == Chk) return false;
	Visit[v] = Chk;
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
	scanf("%d%d", &N, &M);
	for(int i=0; i<M; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		x++; y++;
		Edge[x].push_back(y);
	}

	int flow = 0;
	for(int i=1; i<=N; i++)
	{
		Chk = i;
		if(findMatch(i)) flow++;
	}
	if(flow == N) puts("YES");
	else puts("NO");
	return 0;
}
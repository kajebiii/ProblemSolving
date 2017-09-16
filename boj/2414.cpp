#include <stdio.h>
#include <vector>

using namespace std;

const int MAX_N = 55;

int N, M;
char Map[MAX_N][MAX_N];
int CntN[2], Cnts[MAX_N][MAX_N][2]; // 0 ->, 1 |
int Visit[MAX_N*MAX_N], Match[MAX_N*MAX_N];
vector<int> Edge[MAX_N*MAX_N];

bool findMatch(int v)
{
	if(Visit[v] == 1) return false;
	Visit[v] = 1;

	for(int &w : Edge[v])
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
	for(int i=1; i<=N; i++) scanf("%s", Map[i]+1);
	for(int i=1; i<=N; i++) Map[i][0] = Map[i][M+1] = '.';
	for(int i=1; i<=M; i++) Map[0][i] = Map[N+1][i] = '.';
	for(int i=1, &cnt=CntN[0]; i<=N; i++) for(int j=1; j<=M; j++)
		if(Map[i][j] == '.') Cnts[i][j][0] = 0;
		else Cnts[i][j][0] = (Map[i][j-1] == '.')?++cnt:Cnts[i][j-1][0];
	for(int j=1, &cnt=CntN[1]; j<=M; j++) for(int i=1; i<=N; i++)
		if(Map[i][j] == '.') Cnts[i][j][1] = 0;
		else Cnts[i][j][1] = (Map[i-1][j] == '.')?++cnt:Cnts[i-1][j][1];

	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) if(Map[i][j] == '*')
		Edge[Cnts[i][j][0]].push_back(Cnts[i][j][1]);

	int ans = 0;
	for(int i=1; i<=CntN[0]; i++)
	{
		for(int j=1; j<=CntN[0]; j++) Visit[j] = 0;
		if(findMatch(i)) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
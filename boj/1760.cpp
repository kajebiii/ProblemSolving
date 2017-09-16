#include <stdio.h>
#include <vector>

using namespace std;

const int MAX_N = 111, MAX_V = MAX_N * MAX_N;

int N, M, Nr[MAX_N][MAX_N];
int Cnt[MAX_N][MAX_N][2], CntN[2];
vector<int> Edge[MAX_V];
bool Visit[MAX_V]; int Match[MAX_V];
bool findMatch(int v)
{
	if(Visit[v] == 1) return false;
	Visit[v] = 1;
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
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) scanf("%d", &Nr[i][j]);
	for(int i=1, k=0, &cnt = CntN[k]; i<=N; i++) for(int j=1; j<=M; j++)
		if(Nr[i][j] == 2) Cnt[i][j][k] = 0;
		else Cnt[i][j][k] = (j==1 || Nr[i][j-1]==2) ? ++cnt : Cnt[i][j-1][k];
	for(int j=1, k=1, &cnt = CntN[k]; j<=M; j++) for(int i=1; i<=N; i++)
		if(Nr[i][j] == 2) Cnt[i][j][k] = 0;
		else Cnt[i][j][k] = (i==1 || Nr[i-1][j]==2) ? ++cnt : Cnt[i-1][j][k];
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) if(Nr[i][j] == 0)
		Edge[Cnt[i][j][0]].push_back(Cnt[i][j][1]);

	int ans = 0;
	for(int i=1; i<=CntN[0]; i++)
	{
		for(int j=1; j<=CntN[0]; j++) Visit[j] = 0;
		if(findMatch(i)) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
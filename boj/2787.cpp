#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 2e2 + 10;

int N, M, Impo[MAX_N][MAX_N];
void plusRect(int x0, int y0, int x1, int y1)
{
	Impo[x0][y0]++;
	Impo[x0][y1+1]--;
	Impo[x1+1][y0]--;
	Impo[x1+1][y1+1]++;
}
vector<int> Edge[MAX_N];
bool doInit()
{
	scanf("%d%d", &N, &M);
	bool isCan = true;
	for(int m=0; m<M; m++)
	{
		int t, x, y, v;
		scanf("%d%d%d%d", &t, &x, &y, &v);
		if(x > y) swap(x, y);
		plusRect(v, 1, v, x-1), plusRect(v, y+1, v, N);
		if(t == 1) plusRect(v+1, x, N, y);
		if(t == 2) plusRect(1, x, v-1, y);
		if(t == 1 && v > N) isCan = false;
		if(t == 2 && v < 1) isCan = false;
	}
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
	{
		Impo[i][j] += Impo[i-1][j] + Impo[i][j-1] - Impo[i-1][j-1];
		if(Impo[i][j] == 0) Edge[i].push_back(j);
	}
	return isCan;
}

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
	if(doInit())
	{
		int flow = 0;
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++) Visit[j] = false;
			if(findMatch(i)) flow++;
		}
		if(flow != N) puts("-1");
		else for(int i=1; i<=N; i++) printf("%d ", Match[i]);
	}else puts("-1");
	return 0;
}
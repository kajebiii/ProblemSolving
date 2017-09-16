#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e2 + 10;

int N[2], S, V;
vector<int> Edge[MAX_N];
long double Nr[2][MAX_N][2];
long double getDis(int i, int j)
{
	long double dx = Nr[0][i][0] - Nr[1][j][0];
	long double dy = Nr[0][i][1] - Nr[1][j][1];
	return dx * dx + dy * dy;
}
void makeGraph()
{
	for(int n=0; n<2; n++)
		for(int i=1; i<=N[n]; i++)
			scanf("%Lf%Lf", &Nr[n][i][0], &Nr[n][i][1]);
	for(int i=1; i<=N[0]; i++) for(int j=1; j<=N[1]; j++)
		if(getDis(i, j) <= (S*V*S*V))
			Edge[i].push_back(j);
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
	while(scanf("%d%d%d%d", &N[0], &N[1], &S, &V) == 4)
	{
		makeGraph();
		int flow = 0;
		for(int i=1; i<=N[1]; i++) Match[i] = 0;
		for(int i=1; i<=N[0]; i++)
		{
			for(int j=1; j<=N[0]; j++) Visit[j] = false;
			if(findMatch(i)) flow++;
		}
		printf("%d\n", N[0] - flow);
		for(int i=1; i<=N[0]; i++)
		{
			vector<int> temp;
			Edge[i].swap(temp);
		}
	}
	return 0;
}
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

const int MAX_N = 1e2 + 10;

int N, P, Pi[MAX_N][3], Te[MAX_N][2];
long double T[MAX_N][MAX_N];
long double getDis(int i, int j)
{
	int dx = Pi[i][0] - Te[j][0];
	int dy = Pi[i][1] - Te[j][1];
	return sqrt((long double)1.0 * dx * dx + (long double)1.0 * dy * dy) / Pi[i][2];
}
void makeGraph()
{
	scanf("%d%d", &N, &P);
	for(int i=0; i<=P; i++) for(int j=0; j<3; j++)
		scanf("%d", &Pi[i][j]);
	for(int i=0; i<=N; i++) for(int j=0; j<2; j++)
		scanf("%d", &Te[i][j]);
	for(int i=1; i<=P; i++) for(int j=1; j<=N; j++)
		T[i][j] = getDis(i, j);
}

bool Visit[MAX_N]; int Match[MAX_N];
bool findMatch(int v, long double &m)
{
	if(Visit[v]) return false;
	Visit[v] = true;
	for(int i=1; i<=N; i++)
		if(T[v][i] <= m)
			if(Match[i] == 0 || findMatch(Match[i], m))
			{
				Match[i] = v;
				return true;
			}
	return false;
}
int main()
{
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		makeGraph();
		long double ans = -1;
		for(long double l=0, r=20000; l+1e-12<r;)
		{
			long double m = (l+r)/2;
//			printf("%Lf %Lf\n", l, r);
			for(int i=1; i<=N; i++) Match[i] = 0;
			int flow = 0;
			for(int i=1; i<=P; i++)
			{
				for(int j=1; j<=P; j++) Visit[j] = false;
				if(findMatch(i, m)) flow++;
			}
			if(flow == N) r = m;
			else l = m;
			ans = l;
		}
		printf("%.10Lf\n", ans + getDis(0, 0));
	}
	return 0;
}
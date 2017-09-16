#include <stdio.h>
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;

int N, V[2][2];

int main()
{
	scanf("%d", &N);
	V[0][0] = V[1][0] = INF;
	V[0][1] = V[1][1] = -INF;
	for(int i=0; i<N; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		int v[2] = {x+y, x-y};
		for(int k=0; k<2; k++)
		{
			V[k][0] = min(V[k][0], v[k]);
			V[k][1] = max(V[k][1], v[k]);
		}
	}
	printf("%d\n", max(V[0][1]-V[0][0], V[1][1]-V[1][0]));
	return 0;
}
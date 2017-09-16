#include <stdio.h>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

const int MAX_N = 55, MAX_SUM = 5e5 + 100, BASE = 5e5;

int Dy[MAX_SUM * 2];
int N, Nr[MAX_N];

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	for(int j=0; j<2*MAX_SUM; j++)
		Dy[j] = -1;
	Dy[BASE] = 0;

	for(int i=0; i<N; i++)
	{
		queue<pair<int, int>> Q;
		for(int j=0; j<2*MAX_SUM; j++)
			if(Dy[j] != -1)
				Q.push(make_pair(j - Nr[i], Dy[j])),
				Q.push(make_pair(j + Nr[i], Dy[j] + Nr[i]));
		while(!Q.empty())
		{
			int nj, nv; tie(nj, nv) = Q.front(); Q.pop();
			Dy[nj] = max(Dy[nj], nv);
		}
	}

	int ans = Dy[BASE];
	if(ans == 0) puts("-1"); else printf("%d\n", ans);
	return 0;
}
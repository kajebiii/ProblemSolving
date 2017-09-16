#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 111, INF = 0x7fffffff;
const long long LINF = 1ll * INF * INF;

int N, Fi, SumDis[MAX_N];
long long Dy[MAX_N][MAX_N][2]; // left right
int getDis(int a, int b) 
{
	if(a > b) swap(a, b);
	return SumDis[b-1] - SumDis[a-1];
}
int main()
{
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d%d", &N, &Fi);
		for(int i=1; i<N; i++)
			scanf("%d", &SumDis[i]), SumDis[i] += SumDis[i-1];
		for(int i=1; i<=N; i++) for(int j=i; j<=N; j++)
			Dy[i][j][0] = Dy[i][j][1] = LINF;
		Dy[Fi][Fi][0] = Dy[Fi][Fi][1] = 0;
		for(int k=0; k<N-1; k++)
			for(int i=1, j=k+1, l; j<=N; i++, j++)
			{
				l = i-1;
				if(Dy[i][j][0] != LINF) 
					Dy[l][j][0] = min(Dy[l][j][0], Dy[i][j][0] + 1ll * (N-1-k) * getDis(l, i));
				if(Dy[i][j][1] != LINF)
					Dy[l][j][0] = min(Dy[l][j][0], Dy[i][j][1] + 1ll * (N-1-k) * getDis(l, j));
				l = j+1;
				if(Dy[i][j][0] != LINF)
					Dy[i][l][1] = min(Dy[i][l][1], Dy[i][j][0] + 1ll * (N-1-k) * getDis(l, i));
				if(Dy[i][j][1] != LINF) 
					Dy[i][l][1] = min(Dy[i][l][1], Dy[i][j][1] + 1ll * (N-1-k) * getDis(l, j));
			}
		printf("%lld\n", min(Dy[1][N][0], Dy[1][N][1]));
	}

	return 0;
}
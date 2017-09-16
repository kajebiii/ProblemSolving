#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 55;

int N, Nr[MAX_N][MAX_N];
int Sum[MAX_N][MAX_N];
int Cnt[6500000];

int main()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) scanf("%d", &Nr[i][j]);
	int ans = 0;
	for(int k=0; k<2; k++)
	{
		for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
			Sum[i][j] = Sum[i-1][j] + Sum[i][j-1] - Sum[i-1][j-1] + Nr[i][j];
		for(int x=1; x<N; x++) for(int y=1; y<N; y++)
		{

			int base = 6500000 / 2;
			for(int a=1; a<=x; a++) for(int b=1; b<=y; b++)
				Cnt[base + Sum[x][y]-Sum[a-1][y]-Sum[x][b-1]+Sum[a-1][b-1]]++;
			int c=x+1, d=y+1;
			for(int a=c; a<=N; a++) for(int b=d; b<=N; b++)
				ans += Cnt[base + Sum[a][b]-Sum[c-1][b]-Sum[a][d-1]+Sum[c-1][d-1]];
			for(int a=1; a<=x; a++) for(int b=1; b<=y; b++)
				Cnt[base + Sum[x][y]-Sum[a-1][y]-Sum[x][b-1]+Sum[a-1][b-1]]--;
		}
		for(int i=1; i<=N; i++)
			for(int j=1; j*2<=N; j++) 
				swap(Nr[i][j], Nr[i][N+1-j]);
	}
	printf("%d\n", ans);
	return 0;
}

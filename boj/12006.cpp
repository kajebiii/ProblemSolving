#include <stdio.h>

const int MAX_N = 10, MAX_K = 15;

int N, K; char Mv[2][MAX_N][MAX_N];
char Mp[MAX_K][MAX_N][MAX_N];
bool isIn(int o)
{
	return o >= 1 && o <= N;
}
bool moveParallel(int k, int x, int y, char mp[][MAX_N])
{
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) mp[i][j] = '.';
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(Mp[k][i][j] == '#')
		{
			if(!isIn(i+x) || !isIn(j+y)) return false;
			mp[i+x][j+y] = '#';
		}
	return true;
}
int main()
{
	scanf("%d%d", &N, &K);
	for(int k=0; k<=K; k++) for(int i=1; i<=N; i++)
		scanf("%s", Mp[k][i]+1);
	for(int a=1; a<=K; a++) for(int b=a+1; b<=K; b++)
	{
		for(int x=1-N; x<=N-1; x++) for(int y=1-N; y<=N-1; y++)
			for(int n=1-N; n<=N-1; n++) for(int m=1-N; m<=N-1; m++)
			{
				if(!moveParallel(a, x, y, Mv[0])) continue;
				if(!moveParallel(b, n, m, Mv[1])) continue;
				bool isAns = true;
				for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
				{
					bool r = (Mp[0][i][j] == '#');
					bool f[2] = {Mv[0][i][j] == '#', Mv[1][i][j] == '#'};
					if(f[0] & f[1]) isAns = false;
					if(r && !(f[0] | f[1])) isAns = false;
					if(!r && (f[0] | f[1])) isAns = false;
				}
				if(isAns)
				{
					printf("%d %d\n", a, b);
					return 0;
				}
			}
	}
	return 0;
}
#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 4e3 + 100, INF = 0x7fffffff;

int N, Dy[MAX_N], Nr[MAX_N];

int main()
{
	scanf("%d", &N); for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	for(int i=0; i<=N; i++) Dy[i] = INF;
	Dy[0] = 0;
	for(int i=1; i<=N; i++)
	{
		if(Dy[i-1] == INF) continue;
		int now = Nr[i]+1800;
		for(int j=i; j<=N; j++)
		{
			if(Nr[j] >= now)
				now = Nr[j] + 20;
			else
				now += 20;

			if(j == N || Nr[j+1] + 1800 >= now + 60 + 60)
				Dy[j] = min(Dy[j], Dy[i-1] + 60 + (now - Nr[i] - 1800) + 60);
		}
	}
	printf("%d\n", Dy[N]);
	return 0;
}
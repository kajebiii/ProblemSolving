#include <stdio.h>
#include <algorithm>

using namespace std;

int N, M, C, Nr[10];
char Mp[11][11];

int main()
{
	scanf("%d%d%d", &N, &M, &C);
	for(int i=1; i<=C; i++) scanf("%d", &Nr[i]);
	
	int k = 1;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			int x = i, y = j;
			if(i%2 == 0) y = M+1-j;
			while(Nr[k] == 0) k++;
			Mp[x][y] = k + '0';
			Nr[k]--;
		}
	}
	for(int i=1; i<=N; i++) printf("%s\n", Mp[i]+1);
	return 0;
}
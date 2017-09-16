#include <stdio.h>

const int MAX_N = 111;

int N, Nr[MAX_N];

void ans(int lose)
{
	if(lose == 0) puts("koosaga");
	else puts("cubelover");
}
int main()
{
	scanf("%d", &N);
	int  x = 0;
	for(int i=0; i<N; i++) 
	{
		scanf("%d", &Nr[i]);
		if(Nr[i] % 2 == 1) x ^= (Nr[i] / 2 + 1);
		else x ^= (Nr[i] / 2 - 1);
	}
	ans(x == 0);
	return 0;
}
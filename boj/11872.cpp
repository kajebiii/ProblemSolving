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
		if(Nr[i] % 4 == 3) x ^= (Nr[i] + 1);
		else if(Nr[i] % 4 == 0) x ^= (Nr[i] - 1);
		else x ^= Nr[i];
	}
	ans(x == 0);
	return 0;
}
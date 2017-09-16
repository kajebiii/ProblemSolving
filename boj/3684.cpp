#include <stdio.h>

const int MAX_N = 2e2 + 10, MOD = 1e4 + 1;

int N, Nr[MAX_N];

int main()
{
	scanf("%d", &N);
	for(int i=1; i<=2*N-1; i+=2) scanf("%d", &Nr[i]);
	if(N == 1)
	{
		printf("%d\n", Nr[1]);
		return 0;
	}
	for(int a=0; a<=10000; a++) for(int b=0; b<=10000; b++)
	{
		bool flag = true;
		for(int i=3; i<=2*N-1; i+=2)
		{
			int now = (a*a)%MOD*Nr[i-2]%MOD;
			now = (now + ((a+1) * b)) % MOD;
			if(now != Nr[i]) {flag = false; break;}
		}
		if(flag == true)
		{
			for(int i=2; i<=2*N; i+=2)
			{
				int now = (a * Nr[i-1] % MOD + b) % MOD;
				printf("%d\n", now);
			}

			return 0;
		}
	}
	return 0;
}
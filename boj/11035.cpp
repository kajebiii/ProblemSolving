#include <stdio.h>

int N, K;
int Chk[1111];
int main()
{
	int chk = 0;
	while(scanf("%d%d", &N, &K) == 2)
	{
		int ans = -1;
		chk++;
		for(int i=2; i<=N; i++)
		{
			if(Chk[i] == chk) continue;
			for(int j=i; j<=N; j+=i)
				if(Chk[j] != chk)
				{
					Chk[j] = chk;
					K--;
					if(K == 0) ans = j;
				}
			if(ans != -1) break;
		}
		printf("%d\n", ans);
	}
	return 0;
}
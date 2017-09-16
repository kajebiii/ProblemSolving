#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e4 + 100;

int L, N, C, Nr[MAX_N];

int main()
{
	scanf("%d%d%d", &L, &N, &C); 
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	Nr[++N] = L; ++C;
	sort(Nr+1, Nr+N+1);
	int baseL = 0;
	for(int i=1; i<=N; i++) baseL = max(baseL, Nr[i] - Nr[i-1]);

	int ans = L, fV = -1;
	for(int l=baseL, r=L; l<=r; )
	{
		int m = (l + r) >> 1;
		int sum = L+1, cnt = 0;
		for(int i=N; i>=1; i--)
		{
			if(sum + Nr[i] - Nr[i-1] <= m)
			{
				sum += Nr[i] - Nr[i-1];
			}
			else
			{
				sum = Nr[i] - Nr[i-1];
				cnt++;
			}
		}

		if(cnt <= C)
		{
			ans = m;
			r = m-1;
		}
		else l = m+1;
	}

	int firstV = 0, sum = L+1, cnt = 0;
	for(int i=N; i>=1; i--)
	{
		if(sum + Nr[i] - Nr[i-1] <= ans)
		{
			sum += Nr[i] - Nr[i-1];
		}
		else
		{
			sum = Nr[i] - Nr[i-1];
			firstV = Nr[i];
			cnt++;
		}
	}
	if(C > cnt) firstV = Nr[1];
	printf("%d %d\n", ans, firstV);

	return 0;
}
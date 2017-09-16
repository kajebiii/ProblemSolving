#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 25;

int N; char S[MAX_N][MAX_N];
int main()
{
	scanf("%d", &N); for(int i=0; i<N; i++) scanf("%s", S[i]);
	int ans = N * N;
	for(int p=0; p<(1<<N); p++)
	{
		int now = 0;
		for(int i=0; i<N; i++)
		{
			int cnt = 0;
			for(int j=0; j<N; j++)
				if(S[i][j] == 'T')
				{
					if((p & (1<<j)) == 0) cnt++;
				}
				else 
					if((p & (1<<j))) cnt++;
			now += min(cnt, N-cnt);
		}
		ans = min(ans, now);
	}
	printf("%d\n", ans);
	return 0;
}
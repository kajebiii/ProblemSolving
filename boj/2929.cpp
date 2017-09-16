#include <stdio.h>
#include <algorithm>

using namespace std;

char S[222];

int main()
{
	scanf("%s", S);

	int ans = 0;
	for(int i=0, cnt=0; S[i]; i++)
	{
		cnt++;
		if(S[i+1] >= 'A' && S[i+1] <= 'Z')
		{
			if(cnt % 4 != 0) ans += (4 - cnt % 4);
			cnt = 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}
#include <stdio.h>
#include <algorithm>

using namespace std;

int N = 20, Nr[22];

int main()
{
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		int t; scanf("%d", &t);
		int ans = 0;
		for(int i=0; i<N; i++)
		{
			scanf("%d", &Nr[i]);
			for(int j=i-1; j>=0; j--)
			{
				if(Nr[j] > Nr[j+1]) swap(Nr[j], Nr[j+1]);
				else break;
				ans++;
			}
		}
		printf("%d %d\n", t, ans);
	}

	return 0;
}
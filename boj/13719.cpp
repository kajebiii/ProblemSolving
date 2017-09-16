#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e6 + 100;

typedef long long ll;
int N, Nr[MAX_N], Ans;

int main()
{	
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);

	for(int a=0, b=N+1; a+1<b; )
	{
		int l = a+1, r = b-1;
		ll sl = Nr[l], sr = Nr[r]; int cnt = 0;
		bool success = false;
		while(l < r)
		{
			if(sl == sr)
			{
				success = true;
				break;
			}
			if(sl < sr) sl += Nr[++l];
			else if(sl > sr) sr += Nr[--r];
			cnt++;
		}
		if(success)
		{
			a = l;
			b = r;
			Ans += cnt;
		}
		else
		{
			Ans += (b-a-2);
			break;
		}
	}

	printf("%d\n", Ans);
	return 0;
}
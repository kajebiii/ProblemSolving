#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

int N;
set<int> S;

int next(int n)
{
	return n*n/100%10000;
}

int main()
{
	while(scanf("%d", &N) == 1)
	{
		if(N == 0) break;
		S.clear();
		int now = N, cnt = 0;;
		do
		{
			if(S.count(now) == 0) S.insert(now);
			else break;
			cnt++;
			now = next(now);
		}while(true);
		printf("%d\n", cnt);
	}
	return 0;
}
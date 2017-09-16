#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int X, N; scanf("%d%d", &X, &N);
	int Ans = X * (N+1);
	for(int i=0, x; i<N; i++)
	{
		scanf("%d", &x);
		Ans -= x;
	}
	printf("%d\n", Ans);
	return 0;
}
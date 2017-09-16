#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

int N; ll A, B;
int main()
{
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d%lld%lld", &N, &A, &B);
		int Ans = N;
		while(A % 2 == 0 && B % 2 == 0)
		{
			A /= 2; B /= 2;
			Ans--;
		}
		printf("%d\n", Ans);
	}
	return 0;
}
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <string.h>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5; ll MOD = 1e18;

ll F[MAX_N+1];
map<ll, int> Fast;
char getIn[MAX_N];

int main()
{
	F[0] = 0; F[1] = 1;
	for(int i=2; i<=MAX_N; i++) F[i] = (F[i-1] + F[i-2]) % MOD;
	Fast[0] = 0;
	for(int i=2; i<=MAX_N; i++)
	{
		if(Fast.count(F[i]) == 1){printf("bad MOD %d\n", i); return 0;}
		Fast[F[i]] = i;
	}

	int tc; scanf("%d", &tc);
	while(tc--)
	{
		scanf("%s", getIn);
		int N = strlen(getIn);
		ll now = 0;
		for(int i=max(0, N-18); i<N; i++) now *= 10, now += getIn[i] - '0';
		printf("%d\n", Fast[now]);
	}
	return 0;
}
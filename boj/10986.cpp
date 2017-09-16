#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

int N, M, S;
map<int, int> Mp;
int main()
{
	scanf("%d%d", &N, &M);
	Mp[0]++;
	long long ans = 0;
	for(int i=1, x; i<=N; i++)
	{
		scanf("%d", &x);
		S += x; S %= M;
		ans += Mp[S];
		Mp[S]++;
	}
	printf("%lld\n", ans);
	return 0;
}
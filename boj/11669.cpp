#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e6 + 100;

typedef long long ll;

const int INF = 0x7fffffff;
const ll LINF = 1ll * INF * INF;

bool Visit[MAX_N];
ll Dy[MAX_N], N, R, P;

ll getDy(int n)
{
	if(Visit[n]) return Dy[n];
	Visit[n] = true;
	if(n == 1) return Dy[n] = 0;

	Dy[n] = LINF;
	for(int i=1; i*i<=n; i++)
	{
		int g = (n-1) / i;
		// Divide max i
		Dy[n] = min(Dy[n], getDy(i) + g * P + R);

		// Use I print
		int mg = (n + i) / (i+1);
		Dy[n] = min(Dy[n], getDy(mg) + i * P + R);
	}
	return Dy[n];
}
int main()
{
	scanf("%lld%lld%lld", &N, &R, &P);
	printf("%lld\n", getDy(N));
	return 0;
}
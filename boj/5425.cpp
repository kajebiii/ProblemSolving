#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

ll A, B;
ll getVal(ll a, ll p, ll r, ll cnt)
{
	if(a <= 0) return 0;
	ll val = getVal(a/10, p*10, r+a%10*p, cnt+1);
	val += a%10 * (r+1);
	ll sum = 0; for(int i=0; i<a%10; i++) sum += i; sum *= p;
	ll plus = (p / 10) * 45 * cnt;
	val += sum + a%10 * plus;
	return val;
}
int main()
{
	int N; scanf("%d", &N);
	for(int t=0; t<N; t++)
	{
		scanf("%lld%lld", &A, &B);
		printf("%lld\n", getVal(B, 1, 0, 0) - getVal(A-1, 1, 0, 0));
	}
	return 0;
}
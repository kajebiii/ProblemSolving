#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

typedef long long ll;

const int MAX_N = 63;

int N, Nr[MAX_N];
ll getIn()
{
	char now[MAX_N];
	scanf("%s", now+1);
	for(int i=1; i<=N; i++) Nr[i] = now[i] - '0';
	for(int i=1; i<=N; i++) if(Nr[i-1] == 1) Nr[i] = 1 - Nr[i];
	ll ans = 0;
	for(int i=1; i<=N; i++) ans *= 2, ans += Nr[i];
	return ans;
}

int main()
{
	scanf("%d", &N);
	ll a = getIn();
	ll b = getIn();
	printf("%lld\n", abs(a - b) - 1);
	return 0;
}
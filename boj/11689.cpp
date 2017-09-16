#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

ll N;

int main()
{
	cin >> N;
	ll ans = N;
	for(ll i=2; i*i<=N; i++)
	{
		if(N % i != 0) continue;
		ans /= i, ans *= i-1;
		while(N % i == 0) N /= i;
	}
	if(N != 1) ans /= N, ans *= N-1;
	cout << ans;
	return 0;
}
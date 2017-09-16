#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int N; string S[55]; int Chk[10];
ll All[10];
pi Ans[10];
int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++) cin >> S[i];

	for(int p=0; p<N; p++)
	{
		Chk[S[p][0]-'A'] = 1;
		ll cnt[10] = {0};
		for(int i=0; i<S[p].length(); i++)
			for(int j=0; j<10; j++)
				cnt[j] *= 10, cnt[j] += (j == (S[p][i] - 'A'));
		for(int i=0; i<10; i++)
			All[i] += cnt[i];
	}
	for(int i=0; i<10; i++) Ans[i] = make_pair(All[i], i);
	sort(Ans, Ans+10);

	int zero = -1;
	for(int i=9; i>=0; i--) if(Chk[Ans[i].second] == 0) zero = i;

	ll maxV = 0;
	int cnt = 0;
	for(int i=0; i<=9; i++)
		if(zero != i)
			maxV += 1ll * ++cnt * Ans[i].first;

	printf("%lld\n", maxV);
	return 0;
}
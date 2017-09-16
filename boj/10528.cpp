#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
const int MAX_N = 2e3 + 10;

int N, S, T, Nr[MAX_N];
multiset<int> List;
vector<int> Uni;

ll ggcd(ll a, ll b)
{
	return b==0?a:ggcd(b, a%b);
}

int main()
{
	scanf("%d%d%d", &N, &S, &T);
	for(int i=0; i<N; i++) scanf("%d", &Nr[i]), Uni.push_back(Nr[i]);
	sort(Uni.begin(), Uni.end());
	Uni.erase(unique(Uni.begin(), Uni.end()), Uni.end());

	int past = Uni.back() - S;
	ll sum = 0, minV = 0x7fffffffffffffff, maxV = -1;
	for(int st : Uni)
	{
		List.clear();
		for(int i=0; i<N; i++) List.insert(Nr[i]);

		ll ans = 1ll * N * T;
		int now = st;
		for(int i=1; i<N; i++)
		{
			List.erase(List.find(now));
			int next = (now + T) % S, len;
			auto it = List.lower_bound(next);
			if(it == List.end()) 
			{
				it = List.lower_bound(0);
				len = (S - next) + *it;
			}
			else len = *it - next;

			ans += len;
			now = *it;
		}
//		printf("%d : %lld\n", st, ans);
		int maxWait = st - past;
		past = st;
		minV = min(minV, ans);
		maxV = max(maxV, ans + maxWait - 1);
		sum += ans * maxWait + 1ll * (maxWait - 1) * maxWait / 2;
	}
	printf("%lld\n%lld\n", minV, maxV);
	ll gc = ggcd(sum, S);
	printf("%lld/%lld\n", sum/gc, S/gc);
	return 0;
}
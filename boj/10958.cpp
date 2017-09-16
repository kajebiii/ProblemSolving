#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 40 + 5;

int N; ll L, Nr[MAX_N];
vector<ll> List;

int main() {
	scanf("%d%lld", &N, &L);
	for(int i=0; i<N; i++) scanf("%lld", &Nr[i]);

	int rest = (N - N / 2);
	for(int s=0; s<(1<<rest); s++) {
		ll now = 0;
		for(int i=0; i<rest; i++) 
			if(s & (1<<i))
				now += Nr[i+N/2];
		List.push_back(now);
	}
	sort(List.begin(), List.end());
	ll ans = 0;
	for(int s=0; s<(1<<(N/2)); s++) {
		ll now = 0;
		for(int i=0; i<N/2; i++)
			if(s & (1<<i))
				now += Nr[i];
		ans += (upper_bound(List.begin(), List.end(), L - now) - List.begin());
	}
	printf("%lld\n", ans);
	return 0;
}
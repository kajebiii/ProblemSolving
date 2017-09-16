#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 1e3 + 10;

int N, Nr[MAX_N], P;
int main() {
	if(0) {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++) {
		scanf("%d%d", &N, &P);
		for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);

		auto calc = [](ll m) {
			if(m < 0) return 0ll;
			ll cnt = 0;
			for(int i=1; i<=N; i++)
				cnt += m / Nr[i] + 1;
			return cnt;
		};
		ll res = -1;
		for(ll l=0, r=1ll*P*1e5; l<=r; ) {
			ll m = (l + r) >> 1;
			if(calc(m) >= P) res = m, r = m-1; else l = m+1;
		}
		printf("Case #%d: ", tc);
		int ix = P - calc(res - 1);
		for(int i=1; i<=N; i++) {
			if(res % Nr[i] == 0) ix--;
			if(ix == 0) {printf("%d\n", i); break;}
		}
	}
	return 0;
}
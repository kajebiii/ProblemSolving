#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>

using namespace std;

typedef long long ll;

const int MAX_N = 12, MAX_M = 30;

int N, M, Co[MAX_N];
ll Nr[MAX_N];

const int debug = 0, fre = 0;
int main() {
	if(fre) freopen("input.txt", "r", stdin);
	int TC; scanf("%d", &TC);
	while(TC--) {
		map<ll, int> Mp, Sol;
		scanf("%d%d", &N, &M);
		int m[2] = {M/2, M - M/2};
		for(int i=0; i<N; i++) {
			Nr[i] = 0;
			for(int j=0; j<M; j++) {
				int x;
				scanf("%1d", &x);
				Nr[i] *= 2; Nr[i] += x;
			}
			scanf("%d", &Co[i]);
		}
		for(int s=0; s<(1<<m[0]); s++) {
			ll val = 0;
			for(int i=0; i<N; i++) {
				ll diff = (s ^ Nr[i]), cnt = 0;
				for(int j=0; j<m[0]; j++)
					if( (diff & (1ll<<j)) == 0 ) cnt++;
				val *= (M+1); val += cnt;
				if(debug) printf("%d -> [%d : %d]\n", s, i, cnt);
			}
			Mp[val]++;
			Sol[val] = s;
		}
		ll ans = 0, ansV = -1;
		for(int ns=0; ns<(1<<m[1]); ns++) {
			ll s = ((1ll * ns) << m[0]), val = 0;
			bool impos = false;
			for(int i=0; i<N; i++) {
				ll diff = (s ^ Nr[i]), cnt = 0;
				for(int j=m[0]; j<M; j++)
					if((diff & (1ll<<j)) == 0) cnt++;
				if(cnt > Co[i]) {impos = true; break;}
				cnt = Co[i] - cnt;
				val *= (M+1); val += cnt;
			}
			if(impos) continue;
			if(Mp.count(val) != 0) {
				ans += Mp[val];
				ansV = s + Sol[val];
			}
		}
		if(ans == 1) {
			function<void(ll, int)> printAns = [&](ll v, int k) {
				if(k == M) return;
				printAns(v/2, k+1);
				printf("%d", v%2);
			};
			printAns(ansV, 0); puts("");
		}
		else printf("%lld solutions\n", ans);
	}
	return 0;
}

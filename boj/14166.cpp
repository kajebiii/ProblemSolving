#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

const int MAX_N = 1e5 + 100, MAX_K = 1e5 + 100;
typedef long long ll;

int N, K, Fast[MAX_N];
vector<int> Diff[MAX_N];

const int fre = 0;
int main() {
	if(fre) freopen("roboherd.in", "r", stdin);
	if(fre) freopen("roboherd.out", "w", stdout);

	ll base = 0, maxV = 0;
	scanf("%d%d", &N, &K);
	for(int i=0; i<N; i++) {
		int k; scanf("%d", &k);
		int nr[10]; for(int j=0; j<k; j++) scanf("%d", &nr[j]);
		sort(nr, nr+k);
		base += nr[0];
		if(k == 1) {i--; N--; continue;}
		for(int j=0; j<k; j++) Diff[i].push_back(nr[j] - nr[0]);
		maxV += nr[k-1] - nr[0];
	}
	sort(Diff, Diff+N); reverse(Diff, Diff+N);
	for(int i=0; i<N; i++) Fast[i] = Diff[i][1];
	
	ll cnt = 0, plusV = 0, res = -1;
	function<void(int, ll)> findK = [&](int ix, ll val) {
		if(cnt >= K) return;
		if(ix < N && val < Diff[ix][1])
			ix = lower_bound(Fast, Fast+N, val, [&](const int &a, const int &b) {return a > b;}) - Fast;
		if(ix >= N) { cnt++; plusV += (res-1 - val); return; }
		for(int x : Diff[ix]) {
			if(x > val || cnt >= K) break;
			findK(ix+1, val - x);
		}
	};
	for(ll l=0, r = maxV; l <= r; ) {
		ll m = (l + r) >> 1;
		cnt = 0; findK(0, m);
		if(cnt >= K) {res = m; r = m-1;}
		else {l = m+1;}
	}
	cnt = plusV = 0; findK(0, res-1);
	ll ans = base * K + res * (K - cnt) + plusV;
	printf("%lld\n", ans);
	return 0;
}
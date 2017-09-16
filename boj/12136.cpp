#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
typedef pair<ll, ll> pi;

ll gcd(ll a, ll b) {return b==0?a:gcd(b, a%b);}

int N;
void solve() {
	vector<pi> list[2];
	vector<ll> candi;
	scanf("%d", &N);
	vector<ll> nr = vector<ll>(N, 0), cnt = vector<ll>(N, 0);
	rep(i, N) scanf("%lld", &nr[i]);
	ll cntZ = 0;
	rep(i, N) scanf("%lld", &cnt[i]), cntZ = gcd(cntZ, cnt[i]);
	rep(i, N) list[0].emplace_back(nr[i], cnt[i] / cntZ);
	for(ll val = cntZ; val != 1; val /= 2) candi.push_back(0);
	
	for(int t=0; ; t++) {
		int v = t%2, w = 1 - v;
		int vN = list[v].size();
		if(vN == 1) break;
		ll diff = abs(list[v][1].first - list[v][0].first);
		candi.push_back(diff);

		list[w].clear();
		for(int i=0; i<vN; i++) {
			if(list[v][i].second == 0) continue;
			int ix = lower_bound(list[v].begin(), list[v].end(), make_pair(list[v][i].first + diff, -1ll)) - list[v].begin();
			list[v][ix].second -= list[v][i].second;
			list[w].push_back(list[v][i]);
		}
	}
	
//	for(ll val : candi) printf("%d ", val); puts("");

	int ansN = candi.size();
	vector<set<ll>> S = vector<set<ll>>(ansN+1, set<ll>());
	S[0].insert(0);
	rep(i, ansN) {
		ll nr = candi[i];
		S[i+1] = S[i];
		for(ll val : S[i]) S[i+1].insert(val + nr);
	}

	ll maxV = nr[N-1];
	vector<bool> isPlus = vector<bool>(ansN, false);
	for(int i=ansN-1; i>=0; i--) {
		if(S[i].count(maxV) == 1) isPlus[i] = false;
		else maxV -= candi[i], isPlus[i] = true;
	}

	vector<ll> ans;
	rep(i, ansN) ans.push_back(isPlus[i]?candi[i]:-candi[i]);
	sort(ans.begin(), ans.end());
	
	for(ll val : ans) printf("%lld ", val); puts("");
}

const int fre = 0;
int main() {
	if(fre) freopen("input.txt", "r", stdin);
	if(fre) freopen("output.txt", "w", stdout);

	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++) {
		printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}
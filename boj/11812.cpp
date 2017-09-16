#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)((v).size()))
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

ll N; int K, Q;
int getD(ll v) {
	int cnt = 0;
	while(v) v = (v-1) / K, cnt++;
	return cnt;
}
ll getL(ll x, ll y) {
	if(K == 1) return abs(x-y);
	int dx = getD(x), dy = getD(y);
	if(dx > dy) swap(dx, dy), swap(x, y);
	int diff = dy - dx;
	int ans = diff;
	for(int i=0; i<diff; i++) y = (y-1) / K;
	while(x != y) x = (x-1) / K, y = (y-1) / K, ans+=2;
	return ans;
}
int main() {
	cin >> N >> K >> Q;
	while(Q--) {
		ll x, y; scanf("%lld%lld", &x, &y); x--; y--;
		printf("%lld\n", getL(x, y));
	}
	return 0;
}



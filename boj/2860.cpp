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

ll gcd(ll a, ll b){return b==0?a:gcd(b, a%b);}
char rs[11];
int main() {
	ll left, rv=0; int rN;
	scanf("%lld.%s", &left, rs); rN = strlen(rs);
	for(int i=0; i<9; i++) {
		rv *= 10;
		if(i < rN) rv += rs[i] - '0';
	}
	ll a = left * 1000000000 + rv, b = 1e9;
	ll g = gcd(a, b);
	a/=g; b/=g;
	ll Ans[6];
	for(int t=5; t>=1; t--) {
		ll k = a;
		if(t != 1) k = (a-b)/(t-1);
		//max(0ll, a-(t-1)*b);
		Ans[t] = k;
		a -= t * k;
		b -= k;
	}
	for(int t=1; t<=5; t++) printf("%lld ", Ans[t]); puts("");
	return 0;
}



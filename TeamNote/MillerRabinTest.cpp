#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define REPO(i,n) for(int (i)=1; (i)<=(int)(n); (i)++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

ll mul(ll a, ll b, ll mod) {
	a %= mod;
	ll res = 0, p = a;
	while(b) {
		if(b%2) res += p, res %= mod;
		p += p; p %= mod; b>>=1;
	}
	return res;
}
ll a_b(ll a, ll b, ll mod) {
	a %= mod;
	ll res = 1, p = a;
	while(b) {
		if(b%2) res = mul(res, p, mod);
		p = mul(p, p, mod); b>>=1;
	}
	return res;
}


const int MAX_P = 40;
//if n < 18446744073709551616 = 2^64
//it is enough to test a = 2  3  5  7  11  13  17  19  23  29  31  and 37 
vector<int> Ps; bool notP[MAX_P], isFirst = true;
bool isPrime(ll n) { //Miller–Rabin_primality_test
	if(isFirst) {
		isFirst = false;
		notP[0] = notP[1] = true;
		for(int i=2; i<MAX_P; i++) if(notP[i] == false) {
			Ps.push_back(i);
			for(int j=i*2; j<MAX_P; j++) notP[j] = true;
		}
	}
	int s=0; ll m = n-1;
	while((m&1) == 0) m >>= 1, s++;
	for(int x : Ps) if(n % x == 0) return false;

	for(int x : Ps) {
		ll now = a_b(x, m, n);
		bool isCom = true;
		if(now == 1) continue;
		for(int i=0; i<s; i++) {
			if(now == n-1) { isCom = false; break; }
			now = mul(now, now, n);
		}
		if(isCom) return false;
	}
	return true;
}

int main() {
	return 0;
}
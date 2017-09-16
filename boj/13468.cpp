#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;

const int INF = 0x7fffffff;

int B; ll N;
int minD;
vector<int> List;

bool possible() {
	ll n = N;
	for(int i=2; i<B; i++) while(n % i == 0) n /= i;
	return n == 1;
}

unordered_map<ll, int> Cnt, Memo;
int getMin(ll n, int d, int pr) {
	if(Cnt.count(n) > 0) {
		int val = Cnt[n];
		if(val > INF/2 && val - INF/2 <= d) return INF/2;
		if(val <= INF / 2) return Cnt[n];
	}
	if(n < B) { Memo[n] = n; minD = min(minD, d); return Cnt[n] = 1; }
	if(d >= minD) return INF/2;
	for(int i=0; i<List.size(); i++) {
		int p = List[List.size()-i-1];
		ll tempN = n;
		for(int k=0; k<=minD - d; k++) tempN /= p;
		if(tempN > 1) return Cnt[n] = INF/2 + d;
		break;
	}

	int len = INF, ix = -1;
	for(int p : List) if(n % p == 0 && pr * p >= B) {
		int val = getMin(n/p, d+1, p);
		if(len > val) { len = val; ix = p; }
	}
	Memo[n] = ix;
	if(len >= INF/2) return Cnt[n] = INF/2 + d;
	return Cnt[n] = len + 1;
}

int main() {
	scanf("%d%lld", &B, &N);
	if(possible() == false) puts("impossible");
	else {
		if(N == 1) {puts("1"); return 0; }
		for(int i=2; i<B; i++) if(N % i == 0) List.push_back(i);
		//		reverse(List.begin(), List.end());
		ll n = N;
		for(int i=B-1; i>=2; i--) while(n % i == 0) { n /= i; minD++; }
		getMin(N, 1, B);
		vector<int> Ans;
		for(n=N; n>1; n/=Memo[n]) {
//			printf("%lld : %d %d\n", n, Memo[n], Cnt[n]);
			Ans.push_back(Memo[n]);
		}
		reverse(Ans.begin(), Ans.end());

		ll AnsV = 0, pow = 1;
		for(int i=0; i<Ans.size(); i++) {
			AnsV += pow * Ans[i];
			pow *= B;
		}
		printf("%lld\n", AnsV);
	}
	return 0;
}

/*
10000 581318504395200
10000 58190040480
10000 5884320
10000 5810859769934419200
[9996]
[9990]
[9889]
[9840]
[598]
*/
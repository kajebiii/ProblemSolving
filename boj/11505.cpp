#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int N, M, K;
vector<int> Nr;

struct IDX {
	int P; vector<int> val;
	IDX(vector<int> nr) {
		int n = nr.size();
		for(P=1; P<n; P<<=1);
		val = vector<int>(2*P, 0);

		for(int i=0; i<n; i++) val[P+i] = nr[i] % MOD;
		for(int i=P-1; i>=1; i--)
			val[i] = 1ll * val[i*2] * val[i*2+1] % MOD;
	}
	void update(int v, int k) {
		val[v+=P] = k;
		while(v/=2) {val[v] = 1ll * val[v*2] *val[v*2+1] % MOD;}
	}
	int getMulti(int a, int b) {
		int res = 1;
		a += P, b += P;
		while(a <= b) {
			if(a % 2 == 1) res = 1ll * res * val[a++] % MOD;
			if(b % 2 == 0) res = 1ll * res * val[b--] % MOD;
			a/=2; b/=2;
		}
		return res;
	}
};

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for(int i=0, x; i<N; i++)
		scanf("%d", &x), Nr.push_back(x);

	IDX idx = IDX(Nr);
	for(int _=0; _<M+K; _++) {
		int t, a, b; scanf("%d%d%d", &t, &a, &b);
		if(t == 1) idx.update(a-1, b);
		else printf("%d\n", idx.getMulti(a-1, b-1));
	}
	return 0;
}
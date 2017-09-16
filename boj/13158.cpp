#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long ll;

struct ED {
	int w; char c;
	ED() {}
	ED(int w_, char c_) : w(w_), c(c_) {}
};
const int MAX_N = 1e3 + 10, MAX_K = 2e2 + 10;

int N, M, K; char S[MAX_K];
vector<ED> Ed[MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	while(M--) {
		int a, b; char c[2];
		scanf("%d%d%s", &a, &b, c); a--; b--;
		Ed[a].emplace_back(b, c[0]);
		Ed[b].emplace_back(a, c[0]);
	}
	scanf("%s", S); K = strlen(S);

	vector<double> pro, npro;
	pro = vector<double>(N, 0); pro[0] = 100;
	double ans = 0;
	rep(k, K) {
		char chk = S[k];
		npro = vector<double>(N, 0);
		rep(s, N) {
			int cnt = 0;
			for(ED &e : Ed[s]) if(e.c == chk) cnt++;
			if(cnt == 0) {
				npro[s] += pro[s];
				continue;
			}
			for(ED &e : Ed[s]) if(e.c == chk) npro[e.w] += pro[s] / cnt;
		}
		pro = npro;
		ans += pro[N-1]; pro[N-1] = 0;
	}
	printf("%f\n", ans);
	return 0;
}
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX_N = 1e5 + 100, INF = 0x7fffffff;

int N;
struct IDX {
	int P; vector<int> val;
	IDX(int n) {
		for(P=1; P<n; P<<=1);
		val = vector<int>(2*P, INF);
	}
	void update(int v, int k) {
		val[v+=P] = k;
		while(v/=2) val[v] = min(val[v*2], val[v*2+1]);
	}
	int getMin(int a, int b) {
		int res = INF; a+=P, b+=P;
		while(a<=b) {
			if(a%2==1) res = min(res, val[a++]);
			if(b%2==0) res = min(res, val[b--]);
			a/=2;b/=2;
		}
		return res;
	}
};

const int debug = 0, fre = 0;
int main() {
	if(fre) {freopen("input.txt", "r", stdin);}
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d", &N);
		vector<pii> Ps;
		for(int i=0, x, y, z; i<N; i++) scanf("%d%d%d", &x, &y, &z), x--, y--, z--, Ps.push_back(make_pair(x, make_pair(y, z)));
		sort(Ps.begin(), Ps.end());

		IDX idx = IDX(N);
		int ans = 0;
		for(int i=0; i<N; i++) {
			pi now = Ps[i].second;
			int minV = idx.getMin(0, now.first-1);
			if(minV > now.second) {
				ans++;
				idx.update(now.first, now.second);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
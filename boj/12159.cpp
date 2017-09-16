#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <tuple>

using namespace std;

typedef long long ll;
typedef pair<ll, pair<int, int> > pi;

int N;
int main() {
	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++) {
		priority_queue<pi, vector<pi>, greater<pi>> Q;
		scanf("%d", &N);
		int all = 0;
		for(int i=0; i<N; i++) {
			int d, h, m; scanf("%d%d%d", &d, &h, &m);
			for(int j=0; j<h; j++)
				Q.push(make_pair(1ll * (360 - d) * (m+j), make_pair(m+j, 0)));
			all += h;
		}

		int now = all, ans = all, plus = 0, minus = 0;
		while(!Q.empty()) {
			ll t; int nc, ix; pair<int, int> temp;
			tie(t, temp) = Q.top(); Q.pop(); tie(nc, ix) = temp;
			if(ix == 0) minus++, now--; else plus++, now++;
			ans = min(ans, now);
			if(now - (all - minus) >= ans) break;
			Q.push(make_pair(t + 1ll * 360 * nc, make_pair(nc, ix+1)));
		}
		printf("Case #%d: ", tc);
		printf("%d\n", ans);
	}
	return 0;
}
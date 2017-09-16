#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 0x7fffffff, MAX_N = 1e3 + 10;

typedef pair<int, int> pi;
int N; pi Nr[MAX_N]; int D[MAX_N];
int main() {
	int p[2] = {INF, -INF}, m[2] = {INF, -INF};
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		int x, y, d; scanf("%d%d%d", &x, &y, &d);
		x *= 2, y *= 2, d *= 2;
		p[0] = min(p[0], x+y+d); p[1] = max(p[1], x+y-d);
		m[0] = min(m[0], x-y+d); m[1] = max(m[1], x-y-d);
		Nr[i] = make_pair(x, y); D[i] = d;
	}
	if(p[0] < p[1] || m[0] < m[1]) puts("impossible");
	else {
		vector<pi> list;
		for(int i=0; i<2; i++) for(int j=0; j<2; j++) {
			int x = (p[i]+m[j]) / 2, y = (p[i]-m[j])/2;
			if(x % 2 == 1 || y % 2 == 1) continue;
			list.push_back(make_pair( (p[i]+m[j])/2, (p[i]-m[j])/2 ) );
		}
		sort(list.begin(), list.end());
		list.erase(unique(list.begin(), list.end()), list.end());

		vector<pi> candi;
		for(auto &pt : list) {
			int cnt = 0;
			int pp = pt.first + pt.second;
			int pm = pt.first - pt.second;
			for(int k=0; k<N; k++) {
				bool isTrue = false;
				int nrp = Nr[k].first + Nr[k].second;
				int nrm = Nr[k].first - Nr[k].second;
				int np[2] = {nrp+D[k], nrp-D[k]}, nm[2] = {nrm+D[k], nrm-D[k]};
				for(int i=0; i<2; i++) {
					if(np[i] == pp && nm[1] <= pm && pm <= nm[0]) isTrue = true;
					if(nm[i] == pm && np[1] <= pp && pp <= np[0]) isTrue = true;
				}
				if(isTrue) cnt++;
			}
			if(cnt == N) candi.push_back(pt);
		}

		if(candi.size() == 1) printf("%d %d\n", candi[0].first/2, candi[0].second/2);
		else if(candi.size() == 0) puts("impossible");
		else puts("uncertain");
	}
	return 0;
}
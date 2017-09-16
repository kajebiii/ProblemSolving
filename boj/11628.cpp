#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <math.h>

using namespace std;

const int MAX_N = 1e2 + 10;
typedef pair<int, int> pi;

int F, N, Tf[MAX_N][MAX_N], Dis[MAX_N];
vector<int> List[MAX_N];

const int debug = 0;
int main() {
	if(0) freopen("input.txt", "r", stdin);
	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++) {
		scanf("%d%d", &F, &N);
		for(int i=0; i<N; i++) {
			int r, m; scanf("%d%d", &r, &m);
			Dis[i] = r;
			for(int x=r; x<F; x+=m) List[i].push_back(x);
		}
		List[N].push_back(0); Dis[N] = 0; N++;

		for(int i=0; i<N; i++) for(int j=i; j<N; j++) if(i != j) {
			Tf[i][j] = F;
			for(int ix=0, jx=0; ix < List[i].size() && jx < List[j].size(); ) {
				Tf[i][j] = min(Tf[i][j], abs(List[i][ix] - List[j][jx]));
				if(List[i][ix] < List[j][jx]) ix++; else jx++;
			}
			Tf[j][i] = Tf[i][j];
		}else Tf[i][j] = 0;
	

		vector<bool> vis = vector<bool>(N, false);
		for(int t=0; t<N; t++) {
			int minV = F, ix = -1;
			for(int i=0; i<N; i++)
				if(minV > Dis[i] && vis[i] == false)
					minV = Dis[i], ix = i;
			vis[ix] = true;
			for(int i=0; i<N; i++)
				if(Dis[i] > Tf[i][ix] + Dis[ix])
					Dis[i] = Tf[i][ix] + Dis[ix];
		}
		if(debug) for(int i=0; i<N; i++) printf("%d : %d\n", i, Dis[i]);

		auto isPos = [&](int m) {
			// is pos in m stair?
			vector<pi> list;
			for(int i=0; i<N; i++) {
				vector<pi> now;
				if(m < Dis[i]) {
					now.push_back(make_pair(0, F-1));
				}else{
					for(int b=0; b<=List[i].size(); b++) {
						int a = b-1;
						int x = (a>=0 ? List[i][a] : -F), y = (b<List[i].size() ? List[i][b] : 2*F);
						x = max(0, x + m - Dis[i] + 1); y = min(F-1, y - (m - Dis[i]) - 1);
						if(x <= y) now.push_back(make_pair(x, y));
					}
				}
				if(debug) {printf("[%d]\n", i); for(pi &e : now) printf("[%d %d] ", e.first, e.second); puts("");}
				if(i == 0) list = now;
				else {
					vector<pi> next;
					for(int ix = 0, jx = 0; ix < list.size() && jx < now.size(); ) {
						pi &a = list[ix], &b = now[jx];
						if(a.second < b.first) {ix++; continue;}
						if(b.second < a.first) {jx++; continue;}
						next.push_back(make_pair(max(a.first, b.first), min(a.second, b.second)));
						if(a.second < b.second) ix++; else jx++;
					}
					list.swap(next);
				}
			}
			return list;
		};

		int res = -1;
		for(int l=0, r=F; l<=r; ) {
			int m = (l+r) >> 1;
			if(debug) printf("%d started\n", m);
			vector<pi> list = isPos(m);
			if(debug) printf("%d finished\n", m);
			if(list.size() == 0) res = m, r = m-1; else l = m+1;
		}
		if(res == 0) puts("0 0");
		else {
			vector<pi> list = isPos(res-1);
			printf("%d %d\n", res, list[0].first);
		}

		for(int i=0; i<N; i++) List[i].clear(), List[i].shrink_to_fit();
	}
	return 0;
}
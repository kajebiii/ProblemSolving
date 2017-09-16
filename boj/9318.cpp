#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

vector<int> cor[2];
struct NODE {
	int a, b;
	int cnt, all;
	NODE *l, *r;

	NODE(int x, int y) : a(x), b(y), cnt(0), all(0), l(NULL), r(NULL) {
		if(x == y) return;
		int m = (a+b) >> 1;
		l = new NODE(a, m);
		r = new NODE(m+1, b);
	}
	~NODE() {
		if(l != NULL) delete l;
		if(r != NULL) delete r;
	}
	void merge() {
		if(cnt > 0) all = cor[1][b+1] - cor[1][a];
		else all = (l?l->all:0) + (r?r->all:0);
	}

	void update(int x, int y, int p) {
		if(y < a || b < x) return;
		if(x <= a && b <= y) {
			cnt += p;
		}else{
			l -> update(x, y, p);
			r -> update(x, y, p);
		}
		merge();
	}
};
struct LINE {
	int x; vector<int> y; int p;
	LINE() {};
	LINE(int x_, int y0, int y1, int p_) : x(x_), y(vector<int>({y0, y1})), p(p_) {};
};
const int MAX_N = 1e4 + 10;

NODE *root;
int N, Nr[MAX_N][4];
vector<LINE> Ls;

int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d", &N);
		for(int i=0; i<N; i++) for(int j=0; j<4; j++) 
			scanf("%d", &Nr[i][j]), cor[j%2].push_back(Nr[i][j]);
		for(int k=0; k<2; k++) {
			sort(cor[k].begin(), cor[k].end());
			cor[k].erase(unique(cor[k].begin(), cor[k].end()), cor[k].end());
		}
		for(int i=0; i<N; i++) {
			for(int j=0; j<4; j++) 
				Nr[i][j] = lower_bound(cor[j%2].begin(), cor[j%2].end(), Nr[i][j]) - cor[j%2].begin();
			Ls.emplace_back(Nr[i][0], Nr[i][1], Nr[i][3]-1, +1);
			Ls.emplace_back(Nr[i][2], Nr[i][1], Nr[i][3]-1, -1);
		}
		sort(Ls.begin(), Ls.end(), [&](auto &a, auto &b) {
			return a.x < b.x;
		});

		root = new NODE(0, (int)cor[1].size()-1);
		ll ans = 0;
		for(int x=0, i=0; x<cor[0].size(); x++) {
			if(x) {
				ans += 1ll * (cor[0][x] - cor[0][x-1]) * root -> all;
			}
			for(; i<Ls.size() && Ls[i].x == x; i++) {
				root -> update(Ls[i].y[0], Ls[i].y[1], Ls[i].p);
			}
		}
		printf("%lld\n", ans);

		delete root;
		for(int k=0; k<2; k++) cor[k].clear(), cor[k].shrink_to_fit();
		Ls.clear(); Ls.shrink_to_fit();
	}
	return 0;
}
http://joisc2016.contest.atcoder.jp/submissions/1384980

struct NODE {
	int lz, minV;
	int l, r;
	NODE *lp, *rp;
	NODE(int a, int b, int nr[]) : l(a), r(b), lz(0), minV(0), lp(NULL), rp(NULL) {
		if(a == b) {
			minV = nr[a];
			return;
		}
		int m = (a+b) >> 1;
		lp = new NODE(a, m, nr);
		rp = new NODE(m+1, b, nr);
		minV = min(lp->minV, rp->minV);
	}
	void lazy() {
		if(lp) lp->lz += lz;
		if(rp) rp->lz += lz;
		minV -= lz;
		lz = 0;
	}
	void minus(int a, int b, int k) {
		if(b < l || r < a) return;
		if(a <= l && r <= b) {
			lz += k;
			return;
		}
		lazy();
		lp->minus(a, b, k);
		rp->minus(a, b, k);
		minV = min(lp->minV - lp->lz, rp->minV - rp->lz);
	}
	int getMin(int a, int b) {
		if(b < l || r < a) return INF;
		if(a <= l && r <= b) return minV - lz;
		lazy();
		return min(lp->getMin(a, b), rp->getMin(a, b));
	}
}*root;


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

using namespace std;

struct NODE {
	int l, r;
	NODE *lp, *rp;
	bool inv; int sum;

	NODE(int a, int b) {
		l = a; r = b; sum = 0;
		inv = false;
		if(a == b) return;
		int m = (a+b) >> 1;
		lp = new NODE(a, m);
		rp = new NODE(m+1, b);
	}
	void update(int a, int b, int x, int y) {
		if(b < x || y < a) return;
		if(x <= a && b <= y) {
			inv = !inv;
			sum = (b-a+1) - sum;
			return;
		}
		int m = (a+b) >> 1;
		lp->update(a, m, x, y);
		rp->update(m+1, b, x, y);

		sum = lp->sum + rp->sum;
		if(inv) sum = b-a+1 - sum;
	}
	int get(int a, int b, int x, int y, bool now) {
		if(b < x || y < a) return 0;
		if(x <= a && b <= y)
			return now?(b-a+1)-sum:sum;
		int m = (a+b) >> 1;
		now = (inv ? !now : now);
		int val = lp->get(a, m, x, y, now) + rp->get(m+1, b, x, y, now);
		return val;
	}
};

const int MAX_N = 1e5 + 100;

NODE *root;
int N, M;
int main() {
	scanf("%d%d", &N, &M);
	root = new NODE(1, N);
	for(int _=0; _<M; _++) {
		int o, s, t; scanf("%d%d%d", &o, &s, &t);
		if(o == 0) root->update(1, N, s, t);
		else printf("%d\n", root->get(1, N, s, t, false));
	}
	return 0;
}
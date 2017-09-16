#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

struct NODE {
	int l, r, maxIx;
	NODE *lp, *rp;
	NODE() : l(0), r(0), maxIx(0), lp(NULL), rp(NULL) {}
	NODE(int a, int b) : l(a), r(b), maxIx(0), lp(NULL), rp(NULL) {
		if(a == b) return;
		int m = (a+b) >> 1;
		lp = new NODE(a, m);
		rp = new NODE(m+1, b);
	}
	~NODE() {
		if(lp != NULL) delete lp;
		if(rp != NULL) delete rp;
	}
	NODE* add(int lv, int ix) {
		if(l > lv || r < lv) return this;
		NODE *res = new NODE(); res->l=l; res->r=r;
		int m = (l+r) >> 1;
		if(l != r) {
			res->lp = lp->add(lv, ix);
			res->rp = rp->add(lv, ix);
		}
		res->maxIx = max(maxIx, ix);
		return res;
	}
	int findIx(int lv) {
		if(l > lv) return -1;
		if(r <= lv) return maxIx;
		return max(lp->findIx(lv), rp->findIx(lv));
	}
};

const int MAX_N = 3e5 + 100;

int N, Val[MAX_N];
NODE *State[MAX_N];
int main() {
	scanf("%d", &N);
	State[0] = new NODE(0, MAX_N);
	for(int i=1; i<=N; i++) {
		int x; scanf("%d", &x);
		if(x > 0) {
			Val[i] = x;
			State[i] = State[i-1]->add(0, i);
		} else {
			x *= -1;

			int undo = State[i-1]->findIx(x-1) - 1;
			Val[i] = Val[undo];
			State[i] = State[undo]->add(x, i);
		}
		printf("%d\n", Val[i]);
	}
	return 0;
}

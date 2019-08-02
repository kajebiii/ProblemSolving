#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
using ll = long long;
using pi = pair<int, int>;
const int INF = 0x3f3f3f3f;
const ll LINF = 1ll * INF * INF;

using tl = tuple<ll, ll, ll>;

const int MAX_N = 3e5 + 100;

struct NODE {
	NODE *l, *r, *p;
	int val, cnt, minV, maxV; ll sum;
	bool inv;
	NODE(int v_) : l(NULL), r(NULL), p(NULL), val(v_), cnt(1), minV(v_), maxV(v_), sum(1ll*v_), inv(false) {}
}*root;

NODE* memo[MAX_N];
struct SLT {
	static const int DUMMY = 1;

	void update(NODE *x) {
		x->cnt = 1; x->sum = x->minV = x->maxV = x->val;
		if(x->l) {
			x->cnt += x->l->cnt;
			x->sum += x->l->sum;
			x->minV = min(x->minV, x->l->minV);
			x->maxV = max(x->maxV, x->l->maxV);
		}
		if(x->r) {
			x->cnt += x->r->cnt;
			x->sum += x->r->sum;
			x->minV = min(x->minV, x->r->minV);
			x->maxV = max(x->maxV, x->r->maxV);
		}
	}
	void lazyUpdate(NODE *x) {
		if(!(x->inv)) return;
		NODE *t = x->l;
		x->l = x->r;
		x->r = t;
		x->inv = false;
		if(x->l) x->l->inv = !(x->l->inv);
		if(x->r) x->r->inv = !(x->r->inv);
	}
	void rotate(NODE *x) {
		assert(x != root);
		//if(x == root) while(1);
		NODE *p = x->p, *b;
		lazyUpdate(p);
		lazyUpdate(x);
		if(x == p->l)
			p->l = b = x->r, x->r = p;
		else
			p->r = b = x->l, x->l = p;
		x->p = p->p, p->p = x;
		if(b) b->p = p;
		(x->p ? (p == x->p->l ? x->p->l : x->p->r) : root) = x;

		update(p); update(x);
	}
	void splay(NODE *x) {
		while(x->p) {
			NODE *p = x->p, *g = p->p;
			if(g) rotate((x == p->l) == (p == g->l) ? p : x);
			rotate(x);
		}
	}
	void insert(int val, bool isMemo = false) {
		NODE *p = root, **pp, *x = new NODE(val);
		if(isMemo) memo[val] = x;
		if(!p) { root = x; return; }
		while(true) {
			//		if(val == p->val) return; //if not multi-set
			if(val < p->val) pp = &p->l; else pp = &p->r;
			if(!*pp) break; p = *pp;
		}
		*pp = x; x->p = p;
		splay(x);
	}
	bool find(int val) {
		NODE *p = root, **pp;
		if(!p) return false;
		while(p) {
			if(val == p->val) break;
			if(val < p->val) pp = &p->l; else pp = &p->r;
			if(!*pp) break; p = *pp;
		}
		splay(p);
		return val == p->val;
	}
	void erase(int val) {
		if(!find(val)) return;
		NODE *p = root, **pp = NULL;
		if(p->l && p->r) {
			root = p->l; root->p = NULL;
			NODE *x = root;
			while(x->r) x = x->r;
			x->r = p->r; x->r->p = x;
			splay(x);
		} else {
			if(p->l) pp = &p->l;
			if(p->r) pp = &p->r;
			if(pp) {
				root = *pp;
				root->p = NULL;
			}
		}
		delete p;
	}
	void findKth(int k, int dummy = DUMMY) { //0-base
		k += dummy;
		NODE *x = root; lazyUpdate(x);
		while(true) {
			while(x->l && x->l->cnt > k) x = x->l, lazyUpdate(x);
			if(x->l) k -= x->l->cnt;
			if(!k--) break;
			x = x->r, lazyUpdate(x);
		}
		splay(x);
	}
	void interval(int l, int r) {
		findKth(l-1);
		NODE *x = root;
		root = x->r; root->p = NULL;
		findKth(r - l + 1, 0);
		x->r = root; root->p = x;
		root = x;
	}
	void change(int ix, int k) {
		findKth(ix);
		root->sum -= root->val;
		root->sum += (root->val = k);
	}
	void inverse(int l, int r) {
		interval(l, r);
		NODE *x = root->r->l;
		x->inv = !(x->inv);
	}
	tl getQuery(int l, int r) {
		interval(l, r);
		NODE *n = root->r->l;
		return tl(n->minV, n->maxV, n->sum);
	}
	ll getSum(int l, int r) {
		interval(l, r);
		NODE *n = root->r->l;
		return n->sum;
	}
	int getWhere(int x) {
		splay(memo[x]);
		return root->l->cnt;
	}
	SLT(int n) {
		NODE *x;
		for(int i=0; i<DUMMY; i++) insert(0);
		for(int i=0; i<n; i++) insert(i+1, true);
		for(int i=0; i<DUMMY; i++) insert(INF);
	}
};
int N, Q;
int main() {
	cin >> N >> Q;
	SLT slt = SLT(N);
	while(Q--) {
		int t; scanf("%d", &t);
		if(t == 1) {
			int l, r; scanf("%d%d", &l, &r); l--; r--;
			ll minv, maxv, sum; tie(minv, maxv, sum) = slt.getQuery(l, r);
			printf("%lld %lld %lld\n", minv, maxv, sum);
			slt.inverse(l, r);
		}else if(t == 2) {
			int l, r, x; scanf("%d%d%d", &l, &r, &x); l--; r--;
			ll minv, maxv, sum; tie(minv, maxv, sum) = slt.getQuery(l, r);
			printf("%lld %lld %lld\n", minv, maxv, sum);
			x = x % (r-l+1);
			if(x < 0) x = (r-l+1) - abs(x);
			if(x == 0) continue;
			//printf(">> %d %d %d\n", l, r, x);
			slt.inverse(l, r-x);
			slt.inverse(r-x+1, r);
			slt.inverse(l, r);
		}else if(t == 3) {
			int x; scanf("%d", &x); x--;
			ll minv, maxv, sum; tie(minv, maxv, sum) = slt.getQuery(x, x);
			printf("%lld\n", sum);
		}else if(t == 4) {
			int x; scanf("%d", &x);
			printf("%lld\n", slt.getWhere(x));
		}
	}
	for(int i=0; i<N; i++) {
		int x=i;
		ll minv, maxv, sum; tie(minv, maxv, sum) = slt.getQuery(x, x);
		printf("%lld ", sum);
	}
	puts("");
	return 0;
}


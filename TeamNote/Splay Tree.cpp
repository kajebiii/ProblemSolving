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

struct SLT {
	struct NODE {
		NODE *l, *r, *p;
		int val, cnt; ll sum, lazy;
		NODE(int v_) : l(NULL), r(NULL), p(NULL), val(v_), cnt(1), sum(1ll*v_), lazy(0ll) {}
	}*root;
	static const int DUMMY = 1;

	void update(NODE *x) {
		x->cnt = 1; x->sum = x->val;
		if(x->l) x->cnt += x->l->cnt;
		if(x->r) x->cnt += x->r->cnt;
		if(x->l) x->sum += x->l->sum;
		if(x->r) x->sum += x->r->sum;
	}
	void lazyUpdate(NODE *x) {
		x->val += x->lazy;
		if(x->l) {
			x->l->lazy += x->lazy;
			x->l->sum += x->lazy * x->l->cnt;
		}
		if(x->r) {
			x->r->lazy += x->lazy;
			x->r->sum += x->lazy * x->r->cnt;
		}
		x->lazy = 0;
	}
	void rotate(NODE *x) {
		assert(x != root);
		NODE *p = x->p, *b;
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
	void insert(int val) {
		NODE *p = root, **pp, *x = new NODE(val);
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
	void add(int l, int r, int k) {
		interval(l, r);
		NODE *x = root->r->l;
		x->sum += 1ll * x->cnt * k;
		x->lazy += k;
	}
	ll getSum(int l, int r) {
		interval(l, r);
		return root->r->l->sum;
	}
	SLT(int n) : root(NULL) {
		NODE *x;
		for(int i=0; i<n+DUMMY*2; i++) insert(0);
	}
};
int N, M, K;
int main() {
	cin >> N >> M >> K;
	SLT slt = SLT(N);
	for(int i=0, x; i<N; i++) {
		scanf("%d", &x);
		slt.add(i, i, x);
	}
	for(int i=0; i<M+K; i++) {
		int t, x, y; scanf("%d%d%d", &t, &x, &y);
		if(t == 1) {
			int k; scanf("%d", &k);
			slt.add(x-1, y-1, k);
		}else{
			printf("%lld\n", slt.getSum(x-1, y-1));
		}
	}
	return 0;
}


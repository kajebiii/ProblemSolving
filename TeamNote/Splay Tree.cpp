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

struct node {
	node *l, *r, *p;
	int val, cnt; ll sum;
	node(int v_) : l(NULL), r(NULL), p(NULL), val(v_), cnt(1), sum(1ll*v_) {}
}*root;
const int DUMMY = 1;

void update(node *x) {
	x->cnt = 1; x->sum = x->val;
	if(x->l) x->cnt += x->l->cnt;
	if(x->r) x->cnt += x->r->cnt;
	if(x->l) x->sum += x->l->sum;
	if(x->r) x->sum += x->r->sum;
}
void rotate(node *x) {
	assert(x != root);
	node *p = x->p, *b;
	if(x == p->l)
		p->l = b = x->r, x->r = p;
	else
		p->r = b = x->l, x->l = p;
	x->p = p->p, p->p = x;
	if(b) b->p = p;
	(x->p ? (p == x->p->l ? x->p->l : x->p->r) : root) = x;

	update(p); update(x);
}
void splay(node *x) {
	while(x->p) {
		node *p = x->p, *g = p->p;
		if(g) rotate((x == p->l) == (p == g->l) ? p : x);
		rotate(x);
	}
}
void insert(int val) {
	node *p = root, **pp, *x = new node(val);
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
	node *p = root, **pp;
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
	node *p = root, **pp = NULL;
	if(p->l && p->r) {
		root = p->l; root->p = NULL;
		node *x = root;
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
	node *x = root;
	while(true) {
		while(x->l && x->l->cnt > k) x = x->l;
		if(x->l) k -= x->l->cnt;
		if(!k--) break;
		x = x->r;
	}
	splay(x);
}
void interval(int l, int r) {
	findKth(l-1);
	node *x = root;
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
ll getSum(int l, int r) {
	interval(l, r);
	return root->r->l->sum;
}
int N, M, K;
int main() {
	cin >> N >> M >> K;
	for(int i=0; i<N+DUMMY*2; i++) insert(0);
	for(int i=0, x; i<N; i++) {
		scanf("%d", &x);
		change(i, x);
	}
	for(int i=0; i<M+K; i++) {
		int t, x, y; scanf("%d%d%d", &t, &x, &y);
		if(t == 1) change(x-1, y);
		else printf("%lld\n", getSum(x-1, y-1));
	}
	return 0;
}

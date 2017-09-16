#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

struct NODE {
	int l, r, cnt;
	NODE *lp, *rp;
	NODE() : l(0), r(0), cnt(0), lp(NULL), rp(NULL) {}
	NODE(int a, int b) : l(a), r(b), cnt(0), lp(NULL), rp(NULL) {
		if(a == b) return;
		int m = (a+b) >> 1;
		lp = new NODE(a, m);
		rp = new NODE(m+1, b);
	}
	~NODE() {
		if(lp != NULL) delete lp;
		if(rp != NULL) delete rp;
	}
	NODE* add(int val) {
		if(l > val || r < val) return this;
		NODE *res = new NODE(); res->l=l; res->r=r;
		int m = (l+r) >> 1;
		if(l != r) {
			res->lp = lp->add(val);
			res->rp = rp->add(val);
		}
		res->cnt = cnt + 1;
		return res;
	}
};

const int MAX_N = 1e5 + 100, LOG_N = 20;
NODE *root[MAX_N];
int N, Q, Nr[MAX_N], Pa[LOG_N+1][MAX_N], Dep[MAX_N];
vector<int> Ed[MAX_N];

int findKth(NODE *m0, NODE *m1, NODE *p0, NODE *p1, int k) {
	int l = m0->l, r = m0->r;
	if(l == r) return l;
	int leftCnt = p0->lp->cnt + p1->lp->cnt - m0->lp->cnt - m1->lp->cnt;
	if(leftCnt >= k) return findKth(m0->lp, m1->lp, p0->lp, p1->lp, k);
	return findKth(m0->rp, m1->rp, p0->rp, p1->rp, k-leftCnt);
}
int lca(int a, int b) {
	if(Dep[a] > Dep[b]) swap(a, b);
	for(int p=LOG_N; p>=0; p--) if((1<<p) & (Dep[b] - Dep[a])) b = Pa[p][b];
	if(a == b) return a;
	for(int p=LOG_N; p>=0; p--) if(Pa[p][a] != Pa[p][b]) a = Pa[p][a], b = Pa[p][b];
	return Pa[0][a];
}
int main() {
	vector<int> val;
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]), val.push_back(Nr[i]);
	sort(val.begin(), val.end()); val.erase(unique(val.begin(), val.end()), val.end());
	for(int i=1; i<=N; i++) Nr[i] = lower_bound(val.begin(), val.end(), Nr[i]) - val.begin();

	for(int i=1; i<N; i++) {
		int x, y; scanf("%d%d", &x, &y);
		Ed[x].push_back(y); Ed[y].push_back(x);
	}
	root[0] = new NODE(0, (int)val.size()-1);
	function<void(int, int)> dfs = [&](int v, int p) {
		Pa[0][v] = p; Dep[v] = Dep[p]+1;
		root[v] = root[p]->add(Nr[v]);
		for(int w : Ed[v]) if(w != p) dfs(w, v);
	};

	dfs(1, 0);
	for(int p=1; p<=LOG_N; p++) for(int i=1; i<=N; i++) Pa[p][i] = Pa[p-1][Pa[p-1][i]];

	scanf("%d", &Q);
	while(Q--) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		int l = lca(a, b), p = Pa[0][l];
		printf("%d\n", val[findKth(root[p], root[l], root[a], root[b], c)]);
	}
	return 0;
}

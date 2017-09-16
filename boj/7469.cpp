#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

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

const int MAX_N = 1e5 + 100, MAX_M = 5e3 + 100;
NODE *root[MAX_N];
int N, Q, Nr[MAX_N];

int findKth(NODE *m, NODE *p, int k) {
	int l = m->l, r = m->r;
	if(l == r) return l;
	int leftCnt = p->lp->cnt - m->lp->cnt;
	if(leftCnt >= k) return findKth(m->lp, p->lp, k);
	return findKth(m->rp, p->rp, k-leftCnt);
}
int main() {
	vector<int> val;
	scanf("%d%d", &N, &Q);
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]), val.push_back(Nr[i]);
	sort(val.begin(), val.end()); val.erase(unique(val.begin(), val.end()), val.end());
	for(int i=1; i<=N; i++) Nr[i] = lower_bound(val.begin(), val.end(), Nr[i]) - val.begin();

	int maxV = val.size();
	root[0] = new NODE(0, maxV-1);
	for(int i=1; i<=N; i++) root[i] = root[i-1]->add(Nr[i]);

	while(Q--) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		printf("%d\n", val[findKth(root[a-1], root[b], c)]);
	}
	return 0;
}

//BOJ 7469

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
	int getCnt(int a, int b) {
		if(l > b || r < a) return 0;
		if(a <= l && r <= b) return cnt;
		return lp->getCnt(a, b) + rp->getCnt(a, b);
	}
};

const int MAX_N = 1e5 + 100, MAX_M = 5e3 + 100;
const int LOG_N = 10;
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

//use Array
struct cntNode {
	int l, r; int lp, rp;
	int val;
	cntNode() : lp(0), rp(0), val(0) {}
	cntNode(int a, int b) : l(a), r(b), lp(0), rp(0), val(0) {}
};
cntNode idxs[MAX_N * LOG_N * LOG_N / 3 * 2]; int idxCnt = 0;

int init(int a, int b) {
	int now = idxCnt;
	idxs[idxCnt++] = cntNode(a, b);
	if(a == b) return now;
	int m = (a+b) >> 1;
	idxs[now].lp = init(a, m);
	idxs[now].rp = init(m+1, b);
	return now;
}
int update(int now, int v, int k) {
	int &l = idxs[now].l, &r = idxs[now].r, &lp = idxs[now].lp, &rp = idxs[now].rp, &val = idxs[now].val;
	if(v < l || r < v) return now;
	int res = idxCnt++;
	idxs[res] = cntNode(l, r);
	if(l != r) {
		idxs[res].lp = update(lp, v, k);
		idxs[res].rp = update(rp, v, k);
	}
	idxs[res].val = val + k;
	return res;
}
int getCnt(int now, int a, int b) {
	int &l = idxs[now].l, &r = idxs[now].r, &lp = idxs[now].lp, &rp = idxs[now].rp, &val = idxs[now].val;
	if(b < l || r < a) return 0;
	if(a <= l && r <= b) return val;
	return getCnt(lp, a, b) + getCnt(rp, a, b);
}

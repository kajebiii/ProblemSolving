#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

vector<pi> tree[1050000];
int n, q;

void add(int s, int e, int ps, int pe, int p, pi v){
	if(e < ps || pe < s) return;
	if(s <= ps && pe <= e){
		tree[p].push_back(v);
		return;
	}
	int pm = (ps + pe) / 2;
	add(s, e, ps, pm, 2*p, v);
	add(s, e, pm+1, pe, 2*p+1, v);
}

struct ops{
	int type;
	int pos, prev;
};

int pa[300005], r[300005], comp;

int find(int x){
	return pa[x] == x ? x : find(pa[x]);
}

void dfs(int s, int e, int x){
	stack<ops> stk;
	int pcomp = comp;
	for(auto &i : tree[x]){
		int p = find(i.first);
		int q = find(i.second);
		if(p == q) continue;
		comp--;
		if(r[p] > r[q]) swap(p, q);
		stk.push({1, p, pa[p]});
		pa[p] = q;
		if(r[p] == r[q]){
			stk.push({2, q, r[q]});
			r[q]++;
		}
	}
	if(s == e) printf("%d\n", comp);
	else{
		int m = (s+e)/2;
		dfs(s, m, 2*x);
		dfs(m+1, e, 2*x+1);
	}
	while(!stk.empty()){
		auto t = stk.top();
		stk.pop();
		if(t.type == 1){
			pa[t.pos] = t.prev;
		}
		else{
			r[t.pos] = t.prev;
		}
	}
	comp = pcomp;
}

map<pi, int> edg;

struct ins{
	int s, e, u, v;
};

vector<ins> inserts;

int main(){
	freopen("connect.in", "r", stdin);
	freopen("connect.out", "w", stdout);
	int k;
	scanf("%d %d",&n,&k);
	comp = n;
	for(int i=1; i<=n; i++) pa[i] = i;
	while(k--){
		char t[3];
		scanf("%s",t);
		if(*t == '+'){
			int u, v;
			scanf("%d %d",&u,&v);
			if(u > v) swap(u, v);
			edg[pi(u, v)] = q;
		}
		else if(*t == '-'){
			int u, v;
			scanf("%d %d",&u,&v);
			if(u > v) swap(u, v);
			inserts.push_back({edg[pi(u, v)] + 1, q, u, v});
			edg.erase(edg.find(pi(u, v)));
		}
		else{
			q++;
		}
	}
	for(auto &i : edg){
		inserts.push_back({i.second + 1, q, i.first.first, i.first.second});
	}
	for(auto &i : inserts){
		add(i.s, i.e, 1, q, 1, pi(i.u, i.v));
	}
	if(q == 0) return 0;
	dfs(1, q, 1);
}
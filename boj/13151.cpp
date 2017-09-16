#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
typedef pair<int, int> pi;

const int MAX_N = 5e4 + 100;

struct ED {
	int a, b, c;
	ED() {}
	ED(int a_, int b_, int c_) : a(a_), b(b_), c(c_) {}
};

int N, M, L, UNF[MAX_N];
vector<ED> Ed;

int F(int v) {return UNF[v] == v ? v : UNF[v] = F(UNF[v]);}
bool U(int a, int b) {
	a = F(a); b = F(b);
	if(a == b) return false;
	UNF[a] = b;
	return true;
}

int main() {
	scanf("%d%d%d", &N, &M, &L);
	int ans = 0;
	for(int i=0; i<M; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c); 
		if(i < L) ans += c;
		Ed.emplace_back(a, b, c);
	}
	sort(Ed.begin(), Ed.end(), [&](const ED &a, const ED &b) {return a.c < b.c;});

	for(int i=1; i<=N; i++) UNF[i] = i;
	int cnt = 0;
	for(ED &e : Ed) if(U(e.a, e.b)) ans -= e.c, cnt++;
	if(ans < 0 || cnt < N-1) printf("im"); puts("possible");
	return 0;
}
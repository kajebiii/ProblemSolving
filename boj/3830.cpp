#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)((v).size()))
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

int N, M;
pi operator+(pi a, pi b) {return pi(a.one + b.one, a.two + b.two);}
struct UF{
	vector<pi> UNF;
	UF(int n) {
		UNF = vector<pi>(n+1, pi(0, 0));
		for(int i=1; i<=n; i++) UNF[i].one = i;
	}
	pi F(int v) {
		return UNF[v].one == v ? pi(v, 0) : UNF[v] = F(UNF[v].one) + pi(0, UNF[v].two);
	}
	bool U(int a, int b, int c) {
		pi af = F(a), bf = F(b);
		if(af.one == bf.one) return false;
		UNF[af.one] = pi(bf.one, c - af.two + bf.two);
		return true;
	}
};

int main() {
	while(true) {
		scanf("%d%d", &N, &M);
		if(N+M == 0) break;
		UF uf = UF(N);
		for(int m=0; m<M; m++) {
			char s[3]; int x, y;
			scanf("%s%d%d", s, &x, &y);
			if(s[0] == '!') {
				int z; scanf("%d", &z);
				uf.U(x, y, z);
			}else{
				if(uf.F(x).one != uf.F(y).one) puts("UNKNOWN");
				else printf("%d\n", uf.F(x).two - uf.F(y).two);
			}
		}
	}
	return 0;
}



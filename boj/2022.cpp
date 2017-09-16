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

typedef long double ld;

ld X, Y, C;

int main() {
	while(scanf("%Lf%Lf%Lf", &X, &Y, &C) == 3) {
		int cnt = 0; ld ans = 0;
		for(ld l=0, r=1; cnt<=100; cnt++) {
			ld m = (l+r) / 2;
			ld rval = C / m    , rans = Y*Y - rval*rval;
			ld lval = C / (1-m), lans = X*X - lval*lval;
			ans = rans;
			if(rans < lans) l = m; else r = m;
		}
		printf("%.3Lf\n", sqrt(ans));
	}
	return 0;
}



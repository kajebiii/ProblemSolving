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

int X, Y, D, T;
int main() {
	cin >> X >> Y >> D >> T;
	ld d = sqrt(X*X+Y*Y);
	ld ans = d;
	for(int k=-15; k<=15; k++) {
		int now = (int)(d / D) + k;
		if(now < 0) continue;
		ans = min(ans, now * T + abs(d - D * now));
		if(now * D >= d && now >= 2) ans = min(ans, (ld)now * T);
	}
	printf("%.20Lf\n", ans);
	return 0;
}



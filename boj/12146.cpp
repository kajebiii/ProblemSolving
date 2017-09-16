#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7, MAX_N = 1e2 + 10;
int Dy[4][MAX_N][13];

struct BL {int x, y;BL(int x_, int y_) : x(x_), y(y_) {}};
int gcd(int a, int b) {return b==0?a:gcd(b, a%b);}
int getDy(int last, int ix, int period) {
	if(ix < 0) return 0;
	return Dy[last][ix][period];
}

const int fre = 0;
int main() {
	if(fre) freopen("input.txt", "r", stdin);
	if(fre) freopen("output.txt", "w", stdout);

	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++) {
		int N, M; scanf("%d%d", &N, &M);

		vector<BL> Bs;
		if(M % 1 == 0) Bs.emplace_back(1, 1);
		if(M % 3 == 0) Bs.emplace_back(2, 3);
		if(M % 4 == 0) Bs.emplace_back(3, 4);
		if(M % 6 == 0) Bs.emplace_back(2, 6);

		Dy[2][0][1] = Dy[3][0][1] = 1;
		for(int i=1; i<=N; i++) {
			for(int p=1; p<=12; p++)
				Dy[2][i][p] = Dy[3][i][p] = 0;
			// use 2s
			for(BL &b : Bs) {
				int x = b.x, y = b.y;
				for(int p=1; p<=12; p++) {
					int g = gcd(y, p), np = y * p / g;
					Dy[2][i][np] = (Dy[2][i][np] + 1ll * getDy(3, i-x, p) * g) % MOD;
				}
			}
			// use 3s
			for(int p=1; p<=12; p++)
				Dy[3][i][p] = (Dy[3][i][p] + getDy(2, i-2, p)) % MOD;
		}

		int ans = 0;
		for(int last=2; last<=3; last++) for(int p=1; p<=12; p++)
			ans = (ans + Dy[last][N][p]) % MOD;

		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}
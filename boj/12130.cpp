#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 1e6 + 100, INF = 0x3f2f1f0f;

struct EP {
	int s, l, r, ix;
	EP(int s_, int i_) : s(s_), ix(i_), l(s_), r(s_) {}
	bool operator<(const EP &o) const { return ix < o.ix; }
};
int N, D, Nr[2][MAX_N], Val[2][4];

const int fre = 0;
int main() {
	if(fre) freopen("input.txt", "r", stdin);
	if(fre) freopen("output.txt", "w", stdout);

	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++) {
		vector<EP> Es, Ls, Rs;
		scanf("%d%d", &N, &D);
		for(int k=0; k<2; k++) for(int i=0; i<4; i++) scanf("%d", &Val[k][i]);
		for(int k=0; k<2; k++) Nr[k][0] = Val[k][0];
		for(int k=0; k<2; k++) for(int i=1; i<N; i++)
			Nr[k][i] = (Nr[k][i-1] * Val[k][1] + Val[k][2]) % Val[k][3];

		int bossS = Nr[0][0], val = 0;
		for(int i=0; i<N; i++) {
			int p = Nr[1][i] % max(i, 1), s = Nr[0][i];
			EP now = EP(s, i);
			if(i != 0) {
				now.l = min(now.l, Es[p].l);
				now.r = max(now.r, Es[p].r);
			}
			Es.push_back(now);
			if(now.l >= bossS - D && now.r <= bossS) val++;
			//			printf("%d : %d %d\n", i, now.l, now.r);
		}
		Ls = Rs = Es;
		sort(Ls.begin(), Ls.end(), [&](const EP &a, const EP &b) {return a.l < b.l;}); // l increase
		sort(Rs.begin(), Rs.end(), [&](const EP &a, const EP &b) {return a.r < b.r;}); // r increase

		int ans = val, l = bossS - D, r = bossS;
		int ixl = 0, ixr = 0;
		while(ixl < Ls.size() && Ls[ixl].l < l) ixl++;
		while(ixr < Rs.size() && Rs[ixr].r <= r) ixr++;
		while(l <= bossS) {
			while(ixl < Ls.size() && Ls[ixl].l == l) {
				if(Ls[ixl].r <= r) val--;
				ixl++;
			}
			l++;
			while(ixr < Rs.size() && Rs[ixr].r == r+1) {
				if(Rs[ixr].l >= l) val++;
				ixr++;
			}
			r++;
			ans = max(ans, val);
		}

		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}
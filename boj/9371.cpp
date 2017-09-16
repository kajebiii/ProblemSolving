#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int MOD;
struct MAT {
	vector<vector<int>> val;
	MAT() {val = vector<vector<int>>(4, vector<int>(4, 0));}
	MAT(vector<vector<int>> newVal) {val = newVal;}
	MAT(int p) {
		val = vector<vector<int>>(4, vector<int>(4, 0));
		for(int i=0; i<4; i++) val[i][i] = p;
	}
	MAT operator*(MAT &o) {
		MAT res;
		for(int i=0; i<4; i++) for(int j=0; j<4; j++) {
			for(int k=0; k<4; k++)
				res.val[i][j] += (val[i][k] * o.val[k][j]) % MOD;
			res.val[i][j] %= MOD;
		}
		return res;
	}
};
int Nr[2][5], Val[2];
MAT M[2];

int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d", &MOD);
		for(int j=0; j<2; j++) for(int i=0; i<5; i++) scanf("%d", &Nr[j][i]);
		scanf("%d", &Val[0]);
		MAT M[2];
		auto getMat = [&](int k) {
			MAT Base;
			Base.val[0][1] = Base.val[0][2] = 1;
			Base.val[1][3] = Base.val[2][0] = Base.val[3][2] = 1;
			Base.val[1][0] = Base.val[2][1] = Nr[k][3];
			int exp = Nr[k][4] - 1;
			M[k] = MAT(1);
			while(exp) {
				if(exp % 2 == 1) M[k] = M[k] * Base;
				Base = Base * Base;
				exp /= 2;
			}
		};
		for(int k=0; k<2; k++) getMat(k);
//		for(int k=0; k<2; k++, puts("")) for(int i=0; i<4; i++, puts("")) for(int j=0; j<4; j++) printf("%d ", M[k].val[i][j]);
		int coe[2][2];
		for(int k=0; k<2; k++) {
			for(int i=0; i<2; i++) coe[k][i] = 0;
			for(int i=0; i<3; i++) coe[k][0] = (coe[k][0] + Nr[k][i] * M[k].val[0][i]) % MOD;
			coe[k][1] = M[k].val[0][3];
		}
		if(coe[0][1] == 0 && coe[1][1] == 0) {printf("%d\n", coe[1][0]); continue;}
		if(coe[0][1] == 0 && coe[1][1] != 0) {puts("UNKNOWN"); continue;}

		auto getMulti = [&](int n, int k) {
			int res = 1, pow = n;
			while(k) {
				if(k % 2 == 1) res *= pow, res %= MOD;
				pow *= pow; pow %= MOD;
				k /= 2;
			}
			return res;
		};
		int h0 = ( ((Val[0] + MOD - coe[0][0]) % MOD) * getMulti(coe[0][1], MOD-2) ) % MOD;
		Val[1] = (coe[1][0] + coe[1][1] * h0) % MOD;
		printf("%d\n", Val[1]);
	}
	return 0;
}
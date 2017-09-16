#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct COE {
	int a, b, c, ix;
	COE() {}
	COE(int a_, int b_, int c_, int i_) : a(a_), b(b_), c(c_), ix(i_) {}
	bool operator<(const COE &o) const {
		return 1ll * (b*b + 4*a*c) * o.a > 1ll * (o.b*o.b + 4*o.a*o.c) * a;
	}
};
int N;

const int debug = 0, fre = 0;
int main() {
	if(fre) {freopen("input.txt", "r", stdin);}
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d", &N);
		vector<COE> Cs;
		for(int i=0; i<N; i++) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			Cs.emplace_back(a, b, c, i+1);
		}
		sort(Cs.begin(), Cs.end());
		printf("%d\n", Cs[0].ix);
	}
	return 0;
}
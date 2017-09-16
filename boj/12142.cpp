#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

const int MAX_N = 1e2 + 10;
const double EPS = 1e-12;

double V, X; int N;
struct WT{double v, x; WT(double v_, double x_) : v(v_), x(x_) {} };

const int fre = 0;
int main() {
	if(fre) freopen("input.txt", "r", stdin);
	if(fre) freopen("output.txt", "w", stdout);

	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++) {
		scanf("%d%lf%lf", &N, &V, &X);
		vector<WT> Ws;
		for(int i=0; i<N; i++) {
			double v, x; scanf("%lf%lf", &v, &x);
			Ws.emplace_back(v, x);
		}
		sort(Ws.begin(), Ws.end(), [&](const WT &a, const WT &b) {return a.x < b.x;});

		double ans = -1; int cnt = 0, ITER = 500;
		for(double l=0, r=1e20; cnt < ITER; cnt++) {
			double m = (l+r) / 2;

			double maxX = -1, minX = -1;
			double sumXV = 0, sumV = 0;
			for(int i=0; i<N; i++) {
				double v = Ws[i].v, x = Ws[i].x;
				if(V - sumV >= m * v) v *= m; else v = V - sumV;
				sumXV += v * x, sumV += v;
			}
			minX = sumXV / V;
			
			sumXV = 0; sumV = 0;
			for(int i=0; i<N; i++) {
				double v = Ws[N-1-i].v, x = Ws[N-1-i].x;
				if(V - sumV >= m * v) v *= m; else v = (V - sumV);
				sumXV += v * x, sumV += v;
			}
			maxX = sumXV / V;
//			printf("(%f %f) %f : %f %f (%f)\n", l, r, m, minX, maxX, sumV);

			if(minX / X <= 1 + EPS && 1 - EPS <= maxX / X && abs(sumV - V) <= EPS) r = m, ans = m;
			else l = m;
		}
		if(ans < 0) printf("Case #%d: IMPOSSIBLE\n", tc);
		else printf("Case #%d: %.12f\n", tc, ans);
	}
	return 0;
}
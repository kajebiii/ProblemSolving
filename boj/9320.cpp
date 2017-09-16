#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

const double EPS = 1e-7;

int N = 4, Nr[4];
int main() {
	int TC; scanf("%d", &TC);
	function<double(double, double)> op[6] ={
		[&](double a, double b) -> double {return a+b;},
		[&](double a, double b) -> double {return a*b;},
		[&](double a, double b) -> double {return a-b;},
		[&](double a, double b) -> double {return b-a;},
		[&](double a, double b) -> double {return b!=0?a/b:-1e9;},
		[&](double a, double b) -> double {return a!=0?b/a:-1e9;}
	};
	while(TC--) {
		for(int i=0; i<4; i++) scanf("%d", &Nr[i]);
		sort(Nr, Nr+4);
		bool isTrue = false;
		do {
			for(int s=0; s<6*6*6; s++) {
				int ns = s;
				double val = Nr[0];
				for(int i=1; i<4; i++) {
					int t = ns % 6; ns /= 6;
					val = op[t](val, Nr[i]);
					if(val < -1e8) {val = -1; break;}
				}
				if(abs(val-24) < EPS) {isTrue = true; break;}

				ns = s;
				int o[3];
				for(int i=0; i<3; i++) {o[i] = ns % 6; ns /= 6; }
				double vals[2] = {op[o[0]](Nr[0], Nr[1]), op[o[1]](Nr[2], Nr[3])};
				val = op[o[2]](vals[0], vals[1]);
				if(val < -1e8) continue;
				if(abs(val-24) < EPS) { isTrue = true; break; }
			}
			if(isTrue) break;
		}while(next_permutation(Nr, Nr+4));
		puts(isTrue?"YES":"NO");
	}
	return 0;
}
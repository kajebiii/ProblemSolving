#include <stdio.h>
#include <algorithm>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

const int MAX_N = 1e5 + 100;

struct PT {
	int x, y;
	PT() {}
	PT(int x_, int y_) : x(x_), y(y_) {}
	PT operator-(const PT &o) const{return PT(x-o.x, y-o.y);}
	int gccw(const PT &o) const {
		long long val = 1ll * x * o.y - 1ll * y * o.x;
		return (val > 0) - (val < 0);
	}
};
int N; vector<PT> Ps;
int main() {
	scanf("%d", &N);
	for(int i=0, x, y; i<N; i++) 
		scanf("%d%d", &x, &y), Ps.emplace_back(x, y);

	if(N <= 4) {puts("success"); return 0;}

	srand(time(NULL));
	for(int t=0; t<40; t++) {
		int x = rand() % N;
		int y = rand() % (N-1); if(y >= x) y++;
		int cnt = 0, half = (N+1) / 2;
		for(int i=0; i<N; i++)
			if((Ps[x]-Ps[y]).gccw(Ps[i]-Ps[y]) == 0)
				cnt++;
		if(cnt >= half) { // must be answer
			vector<int> ix;
			for(int i=0; i<N; i++)
				if((Ps[x]-Ps[y]).gccw(Ps[i]-Ps[y]) != 0)
					ix.push_back(i);
			if(ix.size() <= 2) {puts("success"); return 0;}
			int a = ix[0], b = ix[1];

			bool isTrue = true;
			for(int i=2; i<ix.size(); i++)
				if((Ps[a]-Ps[b]).gccw(Ps[ix[i]]-Ps[b]) != 0) {
					isTrue = false;
					break;
				}
			if(isTrue) {puts("success"); return 0;}
			else {puts("failure"); return 0;}
		}
	}
	puts("failure");
	return 0;
}

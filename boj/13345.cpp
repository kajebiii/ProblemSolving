#include <stdio.h>
#include <algorithm>
#include <assert.h>

using namespace std;

int N=3;
struct PT {
	int x, y;
	PT() {}
	PT(int x_, int y_) : x(x_), y(y_) {}
	PT operator-(const PT &o) const{return PT(x-o.x, y-o.y); }
};
PT Ps[3];
int dot(const PT &a, const PT &b) {
	return a.x * b.x + a.y * b.y;
}
int main() {
	for(int i=0; i<N; i++) scanf("%d%d", &Ps[i].x, &Ps[i].y);
	for(int i=0; i<N; i++) {
		int j = (i+1) % N;
		int k = (i+2) % N;
		if(dot(Ps[i]-Ps[j], Ps[k]-Ps[i]) == 0) {
			PT val = (Ps[k] - (Ps[i]-Ps[j]));
			printf("%d %d\n", val.x, val.y);
			return 0;
		}
	}
	assert(true);
	return 0;
}
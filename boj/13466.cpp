#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>
#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

double EPS = 1e-9;

struct PT {
	double cor[2];
	PT() {}
	PT(int x_, int y_) { cor[0] = x_; cor[1] = y_; }
	PT(double x_, double y_) { cor[0] = x_; cor[1] = y_; }
	PT operator-(const PT &o) const{return PT(cor[0]-o.cor[0], cor[1]-o.cor[1]); }
	int gccw(const PT &o) const {
		double val = cor[0] * o.cor[1] - cor[1] * o.cor[0];
		if(val > +EPS) return 1;
		if(val < -EPS) return -1;
		return 0;
	}
	bool operator<(const PT &o) const {
		if(cor[0] + EPS < o.cor[0]) return true;
		if(cor[0] > o.cor[0] + EPS) return false;
		return cor[1] < o.cor[1];
	}
};
struct INTER {
	PT pt;
	int ix;
	INTER() {}
	bool operator<(const INTER &o) const {return pt < o.pt;}
};

const int MAX_N = 1e2 + 10;

int N; ll K; int St[2];
string SName[MAX_N];
int Info[MAX_N][2][2];
int FastIx[MAX_N][MAX_N];
double Slope[MAX_N];
vector<INTER> Ed[MAX_N];

INTER findINTER(int x, int y) {
	INTER result; result.ix = -1;
	int ix[2] = {x, y};
	ll val[2][3];
	for(int k=0; k<2; k++) {
		val[k][0] = Info[ix[k]][0][1] - Info[ix[k]][1][1]; // * (x - Info[ix[k]][0][0])
		val[k][1] = Info[ix[k]][1][0] - Info[ix[k]][0][0]; // * (y - Info[ix[k]][0][1])
		val[k][2] = 1ll * Info[ix[k]][0][0] * (val[k][0]) + 1ll * Info[ix[k]][0][1] * val[k][1];
	}
	double inverse[2][2] = { {val[1][1], -val[0][1]}, {-val[1][0], val[0][0]} };
	ll deter = val[0][0] * val[1][1] - val[0][1] * val[1][0];
	if(deter == 0) return result;
	for(int i=0; i<2; i++) for(int j=0; j<2; j++) inverse[i][j] /= deter;

	PT res = PT(inverse[0][0] * val[0][2] + inverse[0][1] * val[1][2], inverse[1][0] * val[0][2] + inverse[1][1] * val[1][2]);
	result.pt = res; result.ix = y;
	return result;
}
void getInter() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) if(i != j) {
			INTER res = findINTER(i, j);
			if(res.ix != -1) 
				Ed[i].push_back(res);
		}
//		assert(Ed[i].size() == N-1); it might be no intersection
		sort(Ed[i].begin(), Ed[i].end());
		for(int j=0; j<Ed[i].size(); j++) FastIx[i][Ed[i][j].ix] = j;
	}
}
void getSlope() {
	for(int i=0; i<N; i++) {
		int diff[2];
		for(int j=0; j<2; j++) diff[j] = Info[i][1][j] - Info[i][0][j];
		if(diff[0] == 0) Slope[i] = 1e9;
		else Slope[i] = (double)diff[1] / diff[0];
	}
}
int main() {
	scanf("%d%lld%d%d", &N, &K, &St[0], &St[1]);
	for(int i=0; i<N; i++) {
		char getName[99]; scanf("%s", getName); SName[i] = getName;
		for(int j=0; j<2; j++) for(int k=0; k<2; k++) scanf("%d", &Info[i][j][k]);
	}
	getInter();
	getSlope();

	int startI = -1, kth = -1;
	PT st = PT(St[0], St[1]);
	for(int i=0; i<N; i++) 
		if((PT(Info[i][0][0], Info[i][0][1]) - st).gccw(PT(Info[i][1][0], Info[i][1][1]) - st) == 0)
			startI = i;
	assert(startI != -1);
	for(int j=0; j<N-1; j++) if(st < Ed[startI][j].pt) {kth = j; break;}
	if(kth == -1 || K == 0) {cout << SName[startI] << endl; return 0;}

	pi now = make_pair(startI, Ed[startI][kth].ix);
	vector<pi> List; List.push_back(now);
	int from = now.first, to = now.second, dir = 1;
	while(K > 0) {
		int nf = to, nt = -1, nd = dir;
		if(Slope[from] < Slope[to]) nd *= -1;
		int ix = FastIx[to][from] + nd;
		K--;
		if(ix < 0 || ix >= Ed[to].size() || K == 0) {cout << SName[nf] << endl; return 0;}
		from = nf; to = nt = Ed[nf][ix].ix; dir = nd;
		now = make_pair(from, to);
		if(List[0] == now) break;
		List.push_back(now);
	}
	K %= List.size();
	cout << SName[List[K].first] << endl;
	return 0;
}
/*
3 4 1 1
Broadway 0 0 0 1
Narrowlane 0 0 1 0
Homedrive 1 1 2 0
3 4 1 0
Broadway 0 0 0 1
Narrowlane 0 0 1 0
Homedrive 1 1 2 0
3 4 3 0
Broadway 0 0 0 1
Narrowlane 0 0 1 0
Homedrive 1 1 2 0
*/


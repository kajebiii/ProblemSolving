#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 5;
typedef pair<int, int> pi;

int Chk[MAX_N][MAX_N], K, Ans;
pi operator+(const pi &a, const pi &b) {return make_pair(a.first + b.first, a.second + b.second);}

void dfs(vector<pi> p, int chkV) {
	for(int l=0; l<2; l++) if(Chk[p[l].first][p[l].second] == 1) return;
	if(chkV <= MAX_N * MAX_N && p[0] == p[1]) return;
	if(chkV > MAX_N * MAX_N) {
		Ans++;
		return;
	}
	for(int l=0; l<2; l++) Chk[p[l].first][p[l].second] = 1;
//	for(int l=0; l<2; l++) printf("[[%d] : %d %d] (%d)\n", l, p[l].first, p[l].second, chkV);
	for(int s=0; s<16; s++) {
		int k[2] = {s/4, s%4};
		vector<pi> np = vector<pi>(2);
		bool impos = false;
		for(int l=0; l<2; l++) {
			np[l] = p[l] + make_pair("1012"[k[l]] - '1', "0121"[k[l]] - '1');
			if(np[l].first < 0 || np[l].second < 0) {impos = true; break;}
			if(np[l].first >= MAX_N || np[l].second >= MAX_N) {impos = true; break;}
		}
		if(impos) continue;
		dfs(np, chkV+2);
	}
	for(int l=0; l<2; l++) Chk[p[l].first][p[l].second] = 0;
	return;
}
int main() {
	scanf("%d", &K);
	for(int i=0, x, y; i<K; i++) scanf("%d%d", &x, &y), Chk[x-1][y-1] = 1;
	dfs(vector<pi>({make_pair(0, 0), make_pair(MAX_N-1, MAX_N-1)}), K + 2);
	printf("%d\n", Ans);
	return 0;
}
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MAX_N = 16;

int N, C, M, Nr[MAX_N][2];
vector<int> Next[1<<MAX_N];
map<int, int> toIx;
int Cnt[1<<MAX_N], Sum[1<<MAX_N];
double Dy[1<<MAX_N][MAX_N+1];
bool Visit[1<<MAX_N][MAX_N+1];

double getDy(int s, int k) {
	double &val = Dy[s][k];
	if(Visit[s][k]) return val; Visit[s][k] = true;
	if(Sum[s] > M) return val = 0;
	if(k >= C) return val = 1;
	for(int ns : Next[s]) {
		int ix = toIx[s - ns];
		double now = (1.0 * Nr[ix][1] / 100 * getDy(ns, k+1))
				   + (1.0 * (100 - Nr[ix][1]) / 100 * getDy(ns, k));
		val = max(val, now);
	}
	return val;
}
int main() {
	for(int i=0; i<MAX_N; i++)
		toIx[1<<i] = i;
	for(int s=0; s<(1<<MAX_N); s++) {
		int cnt = 0;
		for(int i=0; i<MAX_N; i++) 
			if(s & (1<<i)) {
				cnt++;
				Next[s].push_back(s - (1<<i));
			}
		Cnt[s] = cnt;
	}

	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d%d", &N, &C, &M);
		for(int i=0; i<N; i++) for(int j=0; j<2; j++) scanf("%d", &Nr[i][j]);
		for(int s=0; s<(1<<N); s++) {
			Sum[s] = 0;
			for(int i=0; i<N; i++)
				if( (s & (1<<i)) == 0 ) 
					Sum[s] += Nr[i][0];
		}

		for(int s=0; s<(1<<N); s++) for(int i=0; i<=C; i++) 
			Visit[s][i] = Dy[s][i] = 0;
		printf("%.10f\n", getDy((1<<N) - 1, 0));
	}
	return 0;
}
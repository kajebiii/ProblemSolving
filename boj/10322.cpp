#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;


const int MAX_N = 1e5 + 100;
const int debug = 0, fre = 0;

int N, G, Nr[MAX_N][4];

int main() {
	if(fre) {freopen("input.txt", "r", stdin);}
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d", &N, &G);
		for(int i=0; i<N; i++) {
			for(int j=0; j<4; j++) scanf("%d", &Nr[i][j]), Nr[i][j]--;
			swap(Nr[i][2], Nr[i][3]); //then 3 - i is opposite
		}
		vector<bool> vis = vector<bool>(N*2, false);
		int ans = 0;
		for(int i=0; i<2*N; i++) {
			if(vis[i] == true) continue;
			if(debug) puts("");
			int v = i, ix = i % 2;
			bool isIn = false;
			while(vis[v] == false) {
				if((v/2) == (G-1)) isIn = true;
				if(debug) printf(">> %d %d\n", v, ix);
				vis[v] = true;
				int w = Nr[v/2][ix];
				int wix = -1;
				for(int k=0; k<4; k++) if(Nr[w][k] == (v/2) ) wix = k;
				wix = 3 - wix;
				if(debug) printf("%d %d<<\n", w, wix);

				v = w; ix = wix;
				if(wix >= 2) wix = 3 - wix;
				v *= 2; v += wix;
			}
			if(!isIn) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
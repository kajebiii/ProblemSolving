#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
#include <map>

using namespace std;

const int MAX_N = 5e2 + 10;

int N, Q;
int Nr[MAX_N][3], Val[MAX_N][3]; // have / money / contradition?

int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		map<string, int> cNr;
		map<string, int> nNr;
		scanf("%d%d", &N, &Q);
		for(int i=1; i<=N; i++) {
			char cname[55];
			scanf("%s%d%d%d", cname, &Nr[i][0], &Nr[i][1], &Nr[i][2]);
			cNr[cname] = i;
		}
		int nN = 0;
		for(int q=0; q<Q; q++) {
			char nname[55], type[9]; int t;
			scanf("%d%s%s", &t, nname, type);
			if(nNr.count(nname) == 0) {
				nNr[nname] = ++nN;
				Val[nN][0] = Val[nN][1] = Val[nN][2] = 0;
			}
			int ix = nNr[nname];
			if(type[0] == 'p') {
				char cname[55]; scanf("%s", cname);
				if(Val[ix][0] != 0) Val[ix][2] = 1;
				if(Val[ix][2] == 1) continue;
				Val[ix][0] = cNr[cname];
				Val[ix][1] += Nr[Val[ix][0]][1];
			} else if(type[0] == 'r') {
				int killo; scanf("%d", &killo);
				if(Val[ix][0] == 0) Val[ix][2] = 1;
				if(Val[ix][2] == 1) continue;
				Val[ix][1] += (Nr[Val[ix][0]][2] * killo);
				Val[ix][0] = 0;
			} else {
				int per; scanf("%d", &per);
				if(Val[ix][0] == 0) Val[ix][2] = 1;
				if(Val[ix][2] == 1) continue;
				Val[ix][1] += (Nr[Val[ix][0]][0] * per + 99) / 100;
			}
		}
		for(int i=1; i<=nN; i++) 
			if(Val[i][0] != 0) Val[i][2] = 1;

		for(auto &d : nNr) {
			printf("%s ", d.first.c_str());
			int ix = d.second;
			if(Val[ix][2] == 1) puts("INCONSISTENT");
			else {
				printf("%d\n", Val[ix][1]);
			}
		}
	}
	return 0;
}
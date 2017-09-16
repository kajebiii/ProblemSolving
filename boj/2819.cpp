#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
#include <map>

using namespace std;

const int MAX_N = 1e5 + 100, MAX_M = 3e5 + 100;
typedef long long ll;

int N, M; char S[MAX_M];
vector<int> cor[2];
map<char, int> Ch;

int lessEq(int k, int val) {
	return upper_bound(cor[k].begin(), cor[k].end(), val) - cor[k].begin();
}
int main() {
	scanf("%d%d", &N, &M);
	ll ans = 0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<2; j++) {
			int t; scanf("%d", &t);
			cor[j].push_back(t);
			ans += abs(t);
		}
	}
	for(int j=0; j<2; j++)
		sort(cor[j].begin(), cor[j].end());
	scanf("%s", S);
	int ix = 0;for(char x : "SJIZ") Ch[x] = ix++; 
	int co[2] = {0, 0};
	for(int s=0; s<M; s++) {
		int nco[2] = {co[0] + "1120"[Ch[S[s]]] - '1', co[1] + "2011"[Ch[S[s]]] - '1'};
		
		for(int j=0; j<2; j++) {
			if(nco[j] < co[j]) ans += N - 2 * lessEq(j, nco[j]);
			if(nco[j] > co[j]) ans += 2 * lessEq(j, co[j]) - N;
			co[j] = nco[j];
		}
		
		printf("%lld\n", ans);
	}
	return 0;
}
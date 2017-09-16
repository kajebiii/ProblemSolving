#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e1 + 5;
typedef long long ll;

int N, Nr[MAX_N], X, Y;
vector<int> Ans;
void findAns(int ix, int val) {
	if(ix == N) {
		if(val >= X) Ans.push_back(val);
		return;
	}
	int now = val;
	for(int i=0; ; i++) {
		findAns(ix+1, now);
		if(1ll * now * Nr[ix] > Y) break;
		now *= Nr[ix];
	}
}
int main() {
	while(scanf("%d", &N) == 1) {
		if(N == 0) break;
		for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
		scanf("%d%d", &X, &Y);
		
		findAns(0, 1);
		sort(Ans.begin(), Ans.end());

		
		if(Ans.size() == 0) puts("none");
		else {
			printf("%d", Ans[0]);
			for(int i=1; i<Ans.size(); i++) printf(",%d", Ans[i]);
			puts("");			
		}
		vector<int> temp; Ans.swap(temp);
	}
	return 0;
}
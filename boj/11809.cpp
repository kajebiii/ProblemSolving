#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N[2];
vector<int> V[2];
int main() {
	scanf("%d%d", &N[0], &N[1]);
	for(int i=0; i<10; i++) {
		if(N[0] == 0 && N[1] == 0) break;
		if(N[0] == 0 || N[0]%10 <= N[1]%10) V[1].push_back(N[1] % 10);
		if(N[1] == 0 || N[0]%10 >= N[1]%10) V[0].push_back(N[0] % 10);
		N[0] /= 10, N[1] /= 10;
	}
	for(int k=0; k<2; k++) {
		if(V[k].size() == 0) {puts("YODA"); continue;}
		reverse(V[k].begin(), V[k].end());
		int ans = 0;
		for(int x : V[k]) ans *= 10, ans += x;
		printf("%d\n", ans);
	}
	return 0;
}
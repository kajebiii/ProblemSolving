#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 55;

int N, Nr[MAX_N];
vector<int> Ed[MAX_N];

int getDy(int v) {
	vector<int> List;
	for(int w : Ed[v])
		List.push_back(getDy(w));
	sort(List.begin(), List.end());
	int n = List.size();
	int ans = 0;
	for(int i=0; i<n; i++)
		ans = max(ans, List[i] + n - i);
	return ans;
}
int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		int x; scanf("%d", &x); if(x < 0) continue;
		Ed[x].push_back(i);
	}
	printf("%d\n", getDy(0));
	return 0;
}
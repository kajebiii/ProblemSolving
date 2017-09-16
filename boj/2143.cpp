#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e3 + 10;

int T, N[2], Nr[2][MAX_N], Sum[2][MAX_N];
long long ans = 0;
vector<int> List;

int main() {
	scanf("%d", &T);
	for(int k=0; k<2; k++) {
		scanf("%d", &N[k]);
		for(int i=1; i<=N[k]; i++)
			scanf("%d", &Nr[k][i]), Sum[k][i] = Sum[k][i-1] + Nr[k][i];
	}
	for(int i=1; i<=N[0]; i++) for(int j=1; j<=i; j++) 
		List.push_back(Sum[0][i] - Sum[0][j-1]);
	sort(List.begin(), List.end());
	for(int i=1; i<=N[1]; i++) for(int j=1; j<=i; j++)
		ans += upper_bound(List.begin(), List.end(), T-Sum[1][i]+Sum[1][j-1]) 
			 - lower_bound(List.begin(), List.end(), T-Sum[1][i]+Sum[1][j-1]);
	printf("%lld\n", ans);
	return 0;
}
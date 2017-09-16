#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 100;
typedef long long ll;

int N; ll Nr[MAX_N], Sum[MAX_N];

int main() {
	scanf("%d", &N); for(int i=1; i<=N; i++) scanf("%lld", &Nr[i]), Sum[i] = Sum[i-1] + Nr[i];
	stack<int> S; S.push(0);
	ll ans = 0;
	for(int i=1; i<=N+1; i++) {
		while(Nr[S.top()] > Nr[i]) {
			int h = Nr[S.top()]; S.pop();
			int l = S.top() + 1, r = i-1;
			ans = max(ans, h * (Sum[r] - Sum[l-1]));
		}
		S.push(i);
	}
	printf("%lld\n", ans);
	return 0;
}
#include <stdio.h>
#include <algorithm>
#include <stack>

using namespace std;

const int MAX_N = 1e5 + 100;

int N, Nr[MAX_N];
int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	Nr[++N] = 0;
	stack<int> S;
	S.push(0);

	long long ans = 0;
	for(int i=1; i<=N; i++) {
		while(Nr[S.top()] > Nr[i]) {
			int r = i-1;
			int h = Nr[S.top()]; S.pop();
			int l = S.top() + 1;
			ans = max(ans, 1ll*h*(r-l+1));
		}
		S.push(i);
	}
	printf("%lld\n", ans);
	return 0;
}
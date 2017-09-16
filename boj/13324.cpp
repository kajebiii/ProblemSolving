#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <tuple>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

const int MAX_N = 1e6 + 100;

int N, Ix[MAX_N]; priority_queue<int> Q;
int main() {
	scanf("%d", &N);
	long long ans = 0;
	for(int i=1; i<=N; i++) {
		int x; scanf("%d", &x); x -= i;
		if(!Q.empty() && Q.top() > x) {
			ans += Q.top() - x;
			Q.pop(); Q.push(x), Q.push(x);
		}else Q.push(x);
		Ix[i] = Q.top();
	}
	for(int i=N-1; i>=1; i--) Ix[i] = min(Ix[i], Ix[i+1]);
	for(int i=1; i<=N; i++) printf("%d\n", Ix[i]+i);
	return 0;
}

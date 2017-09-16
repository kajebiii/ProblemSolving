#include <stdio.h>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

const int MAX_N = 1e4 + 100;

typedef pair<int, int> pi;

int N, L, P; pi Nr[MAX_N];
int main() {
	scanf("%d", &N);
	for(int i=0, x, y; i<N; i++) scanf("%d%d", &x, &y), Nr[i] = make_pair(x, y);
	sort(Nr, Nr+N);
	scanf("%d%d", &L, &P);
	int now = P, ix = 0, cnt = 0;
	priority_queue<int> Q;
	while(now < L) {
		while(ix < N && Nr[ix].first <= now) Q.push(Nr[ix++].second);
		if(Q.empty() == true) {puts("-1"); return 0;}
		now += Q.top(); Q.pop();
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
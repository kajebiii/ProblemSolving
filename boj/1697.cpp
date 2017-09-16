#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_K = 2e5 + 100;

int Dy[MAX_K];

int main() {
	int S, E; scanf("%d%d", &S, &E);
	Dy[S] = 1;
	queue<int> Q; Q.push(S);

	auto pushVal = [&](int val, int nowDy) {
		if(val < 0 || val >= MAX_K) return;
		if(Dy[val] != 0) return;
		Dy[val] = nowDy + 1;
		Q.push(val);
	};
	while(!Q.empty()) {
		int now = Q.front(); Q.pop();
		if(now == E) break;
		pushVal(now+1, Dy[now]);
		pushVal(now-1, Dy[now]);
		pushVal(now*2, Dy[now]);
	}
	printf("%d\n", Dy[E] - 1);
	return 0;
}
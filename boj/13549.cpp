#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_K = 2e5 + 100;

int Dy[MAX_K];

int main() {
	int S, E; scanf("%d%d", &S, &E);

	queue<int> Q;
	for(; S<MAX_K; S<<=1) {
		Dy[S] = 1;
		Q.push(S);
		if(S == 0) break;
	}

	auto pushVal = [&](int val, int nowDy) {
		if(val < 0 || val >= MAX_K) return;
		for(; val < MAX_K; val<<=1) {
			if(Dy[val] != 0) {
				if(val == 0) break;
				continue;
			}
			Dy[val] = nowDy + 1;
			Q.push(val);
			if(val == 0) break;
		}
	};
	while(!Q.empty()) {
		int now = Q.front(); Q.pop();
		if(now == E) break;
		pushVal(now+1, Dy[now]);
		pushVal(now-1, Dy[now]);
	}
	printf("%d\n", Dy[E] - 1);
	return 0;
}
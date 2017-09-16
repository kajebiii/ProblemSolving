#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <map>

using namespace std;

const int MAX_N = 2e5 + 100;

int N;
map<string, int> Mp;

const int fre = 0;
int main() {
	if(fre) freopen("citystate.in", "r", stdin);
	if(fre) freopen("citystate.out", "w", stdout);

	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		char ci[99], st[9];
		scanf("%s%s", ci, st);
		string C = ci, S = st;
		Mp[C.substr(0, 2) + S]++;
	}

	long long ans = 0;
	for(auto &e : Mp) {
		string C = e.first.substr(0, 2), S = e.first.substr(2, 2);
		int val = e.second;
		if(S != C) ans += 1ll * val * Mp[S + C];
	}
	printf("%lld\n", ans / 2);
	return 0;
}
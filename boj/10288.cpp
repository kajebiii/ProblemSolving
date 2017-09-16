#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N, S, F, K;
vector<int> fav, oth, pt;
bool isPossible(int m) {
	int minV = 0x7fffffff;
	for(int i=0; i<m; i++)
		minV = min(minV, fav[i] + pt[m-1-i]);
	int cnt = 0;
	multiset<int> St;
	for(int i=0; i<N-F; i++)
		St.insert(pt[F + i]);
	for(int i=0; i<N-F; i++) {
		auto it = St.lower_bound(minV - oth[i] + 1);
		if(it == St.begin()) {
			cnt++;
			auto back = St.end(); back--;
			St.erase(back);
		} else {
			it--;
			St.erase(it);
		}
	}
	return cnt <= S - m;
}
int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d%d", &N, &S, &F);
		for(int i=0, x; i<F; i++) 
			scanf("%d", &x), fav.push_back(x);
		sort(fav.begin(), fav.end(), [&](auto a, auto b){return a>b;});
		for(int i=0, x; i<N-F; i++) 
			scanf("%d", &x), oth.push_back(x);
		sort(oth.begin(), oth.end());
		scanf("%d", &K);
		for(int i=0, x; i<K; i++)
			scanf("%d", &x), pt.push_back(x);
		sort(pt.begin(), pt.end(), [&](auto a, auto b) {return a>b;});
		for(int i=0; i<N-K; i++) pt.push_back(0);

		int res = -1;
		for(int l=0, r=min(S, F); l<=r;) {
			int m = (l+r) >> 1;
			if(isPossible(m)) res = m, l = m+1;
			else r = m-1;
		}
		printf("%d\n", res);
		fav.clear(); oth.clear(); pt.clear();
	}
	return 0;
}
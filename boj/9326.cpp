#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e5;

bool notP[MAX_N];
vector<int> Ps;

int N;
int main() {
	notP[1] = true;
	for(int i=2; i<MAX_N; i++) if(notP[i] == false) {
		Ps.push_back(i);
		for(int j=i*2; j<MAX_N; j+=i) notP[j] = true;
	}

	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d", &N);
		vector<int> list;
		for(int p : Ps) {
			if(p * p > N) break;
			int cnt = 0;
			while(N % p == 0) N /= p, cnt++;
			int now = p;
			while(cnt) {
				if(cnt % 2 == 1) list.push_back(now);
				now *= now;
				cnt /= 2;
			}
		}
		if(N > 1) list.push_back(N);
		sort(list.begin(), list.end());
		for(int x : list) printf("%d ", x); puts("");
	}
	return 0;
}
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

bool notP[100000];
vector<int> P;

int main() {
	notP[1] = true; 
	for(int i=2; i*i<=1e9; i++) if(notP[i] == false) {
		for(int j=i*2; j<100000; j+=i) notP[j] = true;
		P.push_back(i);
	}

	int TC; scanf("%d", &TC);
	for(int t=1; t<=TC; t++) {
		ll A, B; int N; scanf("%lld%lld%d", &A, &B, &N);
		vector<int> list;
		for(int p : P) {
			if(N % p == 0) list.push_back(p);
			while(N % p == 0) N /= p;
		}
		if(N != 1) list.push_back(N);

		ll ans = 0;
		for(int s=0; s<(1<<list.size()); s++) {
			int cnt = 0, val = 1;
			for(int i=0; i<list.size(); i++)
				if(s & (1 << i))
					cnt++, val *= list[i];
			ans += (B / val - (A-1) / val) * (1 - (cnt % 2) * 2);
		}
		printf("Case #%d: %lld\n", t, ans);
	}
	return 0;
}
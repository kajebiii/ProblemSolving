#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int SQRT = 100000;

int N, K;
bool notP[SQRT];
vector<int> Ps;

int main() {
	notP[1] = true;
	for(int i=2; i<SQRT; i++) if(notP[i] == false) {
		Ps.push_back(i);
		for(int j=i*2; j<SQRT; j+=i) notP[j] = true;
	}

	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &K);
		bool impossible = false;
		int need = 0;
		for(int p : Ps) {
			int cN = 0, cK = 0;
			while(N % p == 0) cN++, N /= p;
			while(K % p == 0) cK++, K /= p;
			if(cN > 0 && cK == 0) {impossible = true; break;}
			if(cK == 0) continue;
			need = max(need, (cN + cK - 1) / cK);
		}
		if(K == 1 && N != 1) impossible = true;
		if(K == 1 && N == 1) need = max(need, 0);
		if(K != 1 && N == 1) need = max(need, 0);
		if(K != 1 && N != 1) {
			if(K == N) need = max(need, 1);
			else impossible = true;
		}
		if(impossible) puts("unbounded");
		else printf("%d\n", need);
	}

	return 0;
}
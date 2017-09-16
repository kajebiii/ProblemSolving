#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 1e7;

ll Val[MAX_N + 1]; int Chk[MAX_N + 1];
void getAll(ll N) {
	for(int i=1; i<=N; i++) Chk[i] = i, Val[i] = 1;
	for(int i=1; i<=N; i++) {
		if(Chk[i] == 1) continue;
		for(int j=i; j<=N; j+=i) {
			int &now = Chk[j], pow = i;
			int val = 1;
			while(now % i == 0) {
				val += pow;
				pow *= i;
				now /= i;
			}
			Val[j] *= val;
		}
	}
	for(int i=1; i<=N; i++) Val[i] = abs(i*2 - Val[i]), Val[i] += Val[i-1];
}
int main() {
	ll A, B; scanf("%lld%lld", &A, &B);
	getAll(B);
	printf("%lld\n", Val[B] - Val[A-1]);
	return 0;
}
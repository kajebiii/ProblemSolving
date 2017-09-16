#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e3 + 10, MAX_K = 1e2 + 10;

int N, K, Nr[MAX_N], Val[MAX_K], Iv[MAX_K][2];

const int fre = 0;
int main() {
	if(fre) freopen("input.txt", "r", stdin);
	if(fre) freopen("output.txt", "w", stdout);

	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++) {
		scanf("%d%d", &N, &K);
		for(int i=0; i<N-K+1; i++) scanf("%d", &Nr[i]);
		for(int i=0; i<K; i++) Val[i] = Iv[i][0] = Iv[i][1] = 0;
		for(int i=0; i<N-K; i++) {
			Val[i % K] += Nr[i+1] - Nr[i];
			Iv[i % K][0] = min(Val[i % K], Iv[i % K][0]);
			Iv[i % K][1] = max(Val[i % K], Iv[i % K][1]);
		}
		int maxIv = 0, plusVal = 0, baseSum = 0;
		for(int i=0; i<K; i++) baseSum += (-10001 + (-Iv[i][0]));
		for(int i=0; i<K; i++) maxIv = max(maxIv, Iv[i][1] - Iv[i][0]);
		for(int i=0; i<K; i++) plusVal += (maxIv - (Iv[i][1] - Iv[i][0]));

		int diff = (Nr[0] - baseSum) % K;

		int ans = maxIv;
		if(diff > plusVal) ans++;

		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}
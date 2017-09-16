#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) { return mp(x.fi+y.fi, x.se+y.se); }

const int INF = 0x7fffffff;

int K, N, F[99], Ch[99];
char A[99], S[99], Ans[99];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	F[0] = 1; for(int i=1; i<=15; i++) F[i] = F[i-1] * i;
	while(fgets(A, 99, stdin))
	{
		sscanf(A, "%s %d", S, &K);
		N = strlen(S);
		for(int i=0; i<N; i++) Ch[i] = 0;
		
		int now = 0; K--;
		if(K >= F[N]) {printf("%s %d = No permutation\n", S, K+1); continue;}
		for(int i=0; i<N; i++)
		{
			int plus = F[N-1-i], cnt = 0;
			while(now + plus <= K) cnt++, now += plus;
			int ix = 0;
			while(cnt >= 0) cnt -= (1 - Ch[ix++]);
			ix--;
			Ch[ix] = 1;
			Ans[i] = A[ix];
		}
		Ans[N] = 0;
		printf("%s %d = %s\n", S, K+1, Ans);
	}
	return 0;
}
#include <stdio.h>
#include <functional>
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
const pi Ch[4] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1) };

const int MAX_N = 1e6 + 100;

int N, F[MAX_N];
char S[MAX_N];

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	while(1)
	{
		scanf("%s", S);
		N = strlen(S);
		if(S[0] == '.' && N == 1) break;

		F[0] = -1;
		for(int i=0, j=-1; i<N; (j<0||S[i]==S[j])?F[++i]=++j:j=F[j]);
		printf("%d\n", N / (N - F[N]) );
	}

	return 0;
}
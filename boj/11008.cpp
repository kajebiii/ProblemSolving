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

const int MAX_N = 1e4 + 100;

char S[MAX_N], A[MAX_N];
int F[MAX_N];
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	int TC; cin >> TC;
	while(TC--)
	{
		scanf("%s %s", S, A);
		int N = strlen(A), K = strlen(S);
		F[0] = -1; for(int i=0, j=-1; i<N; (j<0||A[i]==A[j])?F[++i]=++j:j=F[j] );
		int cnt = 0;
		for(int i=0, j=0; i<K;)
		{
			if(j<0 || S[i] == A[j])
			{
				++i;++j;
				if(j == N)
				{
					cnt++;
					j=0;
				}
			}
			else j = F[j];
		}
		printf("%d\n", K - cnt * N + cnt);
	}

	return 0;
}
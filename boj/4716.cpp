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

const int MAX_N = 1e3 + 10;

int N, A, B;
struct TEAM
{
	int k, a, b;
	TEAM() {}
	const bool operator<(const TEAM &o) const
	{
		return b - a < o.b - o.a;
	}
}T[MAX_N];

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	while(scanf("%d%d%d", &N, &A, &B) == 3)
	{
		if(N == 0) break;
		for(int i=0; i<N; i++) scanf("%d%d%d", &T[i].k, &T[i].a, &T[i].b);
		int dis = 0, AN = 0, BN = 0;
		for(int i=0; i<N; i++) dis += T[i].k * T[i].a, AN += T[i].k;
		sort(T, T+N);
		for(int i=0; i<N; i++)
		{
			int outA = max(AN - A, 0);
			int inB = max(B - BN, 0);

			int use = -1;
			if(T[i].b - T[i].a <= 0)
				use = min(T[i].k, inB);
			else 
				use = min(T[i].k, outA);
			BN += use;
			AN -= use;
			dis += use * (T[i].b - T[i].a);
		}
		printf("%d\n", dis);
	}
	return 0;
}
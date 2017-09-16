// =====================================================================================
//
//       Filename:  12787.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/23/2016 14:27:26
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

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
#include <assert.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

ull Pow[8];
int main() {
	Pow[7] = 1; for(int i=6; i>=0; i--) Pow[i] = Pow[i+1] * 256;
	int TC; cin >> TC;
	while(TC--)
	{
		int type; scanf("%d", &type);
		if(type == 1)
		{
			ull ans = 0, x; char k;
			for(int i=0; i<8; i++) scanf("%llu%c", &x, &k), ans += Pow[i] * x;
			printf("%llu\n", ans);
		}
		else
		{
			ull x; scanf("%llu", &x);
			for(int i=0; i<8; i++)
			{
				ull k = x/Pow[i];
				printf("%llu", x / Pow[i]); x %= Pow[i];
				if(i < 7) printf("."); else puts("");
			}
		}
	}
	return 0;
}











// =====================================================================================
//
//       Filename:  7894.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 15:36:50
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
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

double LOG10[10000001];
int main() {
	for(int i=1; i<=10000000; i++)
		LOG10[i] = LOG10[i-1] + log10(i);
	int T; cin >> T;
	while(T--)
	{
		int N; scanf("%d", &N);
		printf("%d\n", (int)(LOG10[N]) + 1);
	}
	return 0;
}











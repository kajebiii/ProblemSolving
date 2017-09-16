// =====================================================================================
//
//       Filename:  2697.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  10/04/2016 16:36:05
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
const pi Ch[8] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1), mp(-1, -1), mp(-1, 1), mp(1, -1), mp(1, 1)};

int N; char Nr[99];
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		scanf("%s", Nr);
		N = (int)strlen(Nr);
		if(next_permutation(Nr, Nr+N) == false) puts("BIGGEST");
		else puts(Nr);
	}
	return 0;
}











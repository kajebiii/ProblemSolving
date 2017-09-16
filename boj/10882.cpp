// =====================================================================================
//
//       Filename:  10882.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/18/2016 13:26:16
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

int main() {	
	int TC; cin >> TC;
	int H, M, Z; double temp; scanf("%02d:%02d", &H, &M); 
	scanf(" UTC");
	scanf("%lf", &temp); Z = (int)(temp * 2);
	H -= Z/2; M -= Z%2 * 30;
	if(M < 0) H -= 1, M += 60;
	if(H < 0) H += 24;
	while(TC--)
	{
		scanf("\nUTC");
		scanf("%lf", &temp);
		Z = (int)(temp * 2);
		int h = H + Z/2, m = M + Z%2 * 30;
		if(m < 0) h -= 1, m += 60;
		if(m >= 60) h += 1, m -= 60;
		if(h >= 24) h -= 24; if(h < 0) h += 24;
		printf("%02d:%02d\n", h, m);
	}
	return 0;
}











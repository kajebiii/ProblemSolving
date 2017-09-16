// =====================================================================================
//
//       Filename:  2858.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/12/2016 18:37:54
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
	int R, B; cin >> R >> B;
	for(int h=3; h-2<=B; h++)
		if(B % (h-2) == 0)
		{
			int w = B / (h-2) + 2;
			if(R == 2*h + 2*w - 4)
			{
				printf("%d %d\n", max(h, w), min(h, w));
				return 0;
			}
		}
	return 0;
}











// =====================================================================================
//
//       Filename:  2477.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 14:42:44
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
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(0, -1), mp(0, 1), mp(-1, 0), mp(1, 0)};

int main() {
	int K, Ans = 0; cin >> K;
	pi past = mp(0, 0), now = mp(0, 0); 
	for(int i=0; i<6; i++)
	{
		int t, l; cin >> t >> l;
		now = now + mp(Ch[t-1].fi*l, Ch[t-1].se*l);
		Ans += past.fi * now.se - past.se * now.fi;
		past = now;
	}
	cout << abs(Ans) * K / 2;
	return 0;
}











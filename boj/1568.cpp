// =====================================================================================
//
//       Filename:  1568.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 19:21:35
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
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int T[55555], TN, N;
int main() {
	cin >> N;
	T[0] = 0;
	for(TN=1; ; TN++)
	{
		T[TN] = T[TN-1] + TN;
		if(T[TN] > N) break;
	}

	int ans = 0;
	while(N > 0)
	{
		int ix = (int)(upper_bound(T+1, T+TN+1, N) - T - 1);
		ans += ix;
		N -= T[ix];
	}
	cout << ans;
	return 0;
}











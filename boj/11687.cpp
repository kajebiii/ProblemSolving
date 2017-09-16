// =====================================================================================
//
//       Filename:  11687.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/24/2016 02:50:32
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
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int main() {
	int N; cin >> N;
	int s = 1, e = N*5, ans = -1;
	while(s <= e)
	{
		int m = (s+e)>>1;
		int now = m, cnt = 0;
		do{cnt += now / 5;}while(now /= 5);
		if(cnt < N) s = m+1;
		else
		{
			if(cnt == N) ans = m;
			e = m-1;
		}
	}
	cout << ans;
	return 0;
}











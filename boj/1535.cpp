// =====================================================================================
//
//       Filename:  1535.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/24/2016 15:58:36
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
const int MAX_N = 20;

int N, H[MAX_N], S[MAX_N];
int main() {
	cin >> N; 
	for(int i=0; i<N; i++) cin >> H[i];
	for(int i=0; i<N; i++) cin >> S[i];

	int ans = 0;
	for(int p=0; p<(1<<N); p++)
	{
		int h = 100, s = 0;
		for(int i=0; i<N; i++) if(p & (1<<i))
			h -= H[i], s += S[i];
		if(h > 0) ans = max(ans, s);
	}
	cout << ans;
	return 0;
}










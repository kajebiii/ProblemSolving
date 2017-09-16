// =====================================================================================
//
//       Filename:  1744.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/17/2016 22:36:33
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

int N, Nr[11111];
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%d", &Nr[i]); sort(Nr, Nr+N);
	int ans = 0, l = 0, r = N-1;
	while(l+1 < N && Nr[l+1] <= 0) ans += Nr[l] * Nr[l+1], l+=2;
	while(r-1 >= 0 && Nr[r-1] > 1) ans += Nr[r] * Nr[r-1], r-=2;
	for(int i=l; i<=r; i++) ans += Nr[i];
	cout << ans;
	return 0;
}











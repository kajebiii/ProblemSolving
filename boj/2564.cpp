// =====================================================================================
//
//       Filename:  2564.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 14:23:01
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

int R, C, N, Nr[111][2];
int main() {
	cin >> C >> R >> N; 
	for(int i=0; i<N; i++) scanf("%d%d", &Nr[i][0], &Nr[i][1]);
	int X, Y; cin >> X >> Y;
	int sumC[5] = {-1, 0, 2*C+R, 2*C+2*R, C};
	int sumM[5] = {-1, 1, -1, -1, 1};
	int you = sumC[X] + sumM[X] * Y;
	
	int ans = 0;
	for(int i=0; i<N; i++)
	{
		int store = sumC[Nr[i][0]] + sumM[Nr[i][0]] * Nr[i][1];
		ans += min(min(abs(store-you), abs(store+2*C+2*R-you)), abs(store-2*C-2*R-you));
	}
	cout << ans;
	return 0;
}











// =====================================================================================
//
//       Filename:  10158.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 23:41:42
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

using namespace std;

typedef pair<int, int> pi;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};

int main() {
	int W, H; cin >> W >> H;
	int P, Q; cin >> P >> Q;
	int T; cin >> T;
	P+=T, Q+=T;
	while(P >= 2*W) P -= 2*W;
	while(Q >= 2*H) Q -= 2*H;
	if(P > W) P = 2*W - P;
	if(Q > H) Q = 2*H - Q;
	cout << P << " " << Q;
	return 0;
}











// =====================================================================================
//
//       Filename:  10822.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 19:31:54
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
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};

int main() {
	int ans; scanf("%d", &ans);
	int x, cnt = 0;
	while(scanf(",%d", &x) == 1)
		ans += x;
	cout << ans;
	return 0;
}











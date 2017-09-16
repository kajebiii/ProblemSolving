// =====================================================================================
//
//       Filename:  2355.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 20:00:52
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
	long long a, b; cin >> a >> b;
	if(a > b) swap(a, b);
	printf("%lld\n", 1ll*(a+b)*(b-a+1) / 2);
	return 0;
}











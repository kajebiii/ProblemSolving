// =====================================================================================
//
//       Filename:  1453.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 19:09:25
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

int Chk[111];
int main() {
	int N; cin >> N;
	int ans = 0;
	for(int x; N--;)
		cin >> x, ans += Chk[x], Chk[x] = 1;
	cout << ans;
	return 0;
}











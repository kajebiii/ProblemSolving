// =====================================================================================
//
//       Filename:  2965.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 13:48:34
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

int main() {
	int A, B, C; cin >> A >> B >> C;
	cout << max(C - B - 1, B - A - 1);
	return 0;
}










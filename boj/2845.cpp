// =====================================================================================
//
//       Filename:  2845.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 00:51:18
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
	int X, Y; cin >> X >> Y;
	for(int x, i=0; i<5; i++)
		cin >> x, cout << x - X*Y << " ";
	return 0;
}











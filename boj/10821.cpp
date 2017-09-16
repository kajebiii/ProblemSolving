// =====================================================================================
//
//       Filename:  10821.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 17:25:41
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
	string S; cin >> S;
	int cnt = 1;
	for(char x : S)
		if(x == ',')
			cnt++;
	cout << cnt;
	return 0;
}











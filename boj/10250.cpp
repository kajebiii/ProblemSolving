// =====================================================================================
//
//       Filename:  10250.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 12:10:08
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

#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

int main() {
	int T; cin >> T;
	for(; T--;)
	{
		int h, w, n; cin >> h >> w >> n;
		printf("%d%02d\n", (n-1)%h + 1, (n-1)/h + 1);
	}
	return 0;
}











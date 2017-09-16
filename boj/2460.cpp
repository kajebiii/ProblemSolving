// =====================================================================================
//
//       Filename:  2460.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/16/2016 22:26:01
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

#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

int main() {
	int m = 0, sum = 0;
	for(int i=0; i<10; i++)
	{
		int x, y; cin >> x >> y;
		sum -= x; sum += y;
		m = max(m, sum);
	}
	cout << m;
	return 0;
}











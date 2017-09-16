// =====================================================================================
//
//       Filename:  2490.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/16/2016 22:19:59
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
	char C[5] = {'D', 'C', 'B', 'A', 'E'};
	for(int o=0; o<3; o++)
	{
		int sum = 0;
		for(int i=0, x; i<4; i++)
			cin >> x, sum += x;
		cout << C[sum] << endl;
	}
	return 0;
}











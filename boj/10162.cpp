// =====================================================================================
//
//       Filename:  10162.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 17:38:41
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
	if(T % 10 == 0)
	{
		cout << T / 300 << " ";
		T %= 300;
		cout << T / 60 << " ";
		T %= 60;
		cout << T / 10;
	}
	else
		printf("-1");
	return 0;
}











// =====================================================================================
//
//       Filename:  3052.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 18:04:03
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
	set<int> S;
	for(int i=0; i<10; i++)
	{
		int x; cin >> x;
		if(S.count(x%42) == 0)
			S.insert(x%42);
	}
	cout << S.size();
	return 0;
}











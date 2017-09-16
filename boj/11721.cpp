// =====================================================================================
//
//       Filename:  11721.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 20:03:38
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
	string S; cin >> S;
	int cnt = 0;
	for(auto x : S)
	{
		cnt++;
		cout << x;
		if(cnt % 10 == 0) 
			cout << endl;
	}
	return 0;
}











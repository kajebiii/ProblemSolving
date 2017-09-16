// =====================================================================================
//
//       Filename:  1789.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 11:15:24
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
	long long S; cin >> S;
	long long i;
	for(i=1; (i+1)*(i+2)/2 <= S; i++);
	cout << i;
	return 0;
}











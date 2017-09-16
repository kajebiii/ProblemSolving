// =====================================================================================
//
//       Filename:  2869.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 22:00:51
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
	int A, B, V; cin >> A >> B >> V;
	cout << ((V-A)+(A-B-1))/(A-B) + 1 << endl;
	return 0;
}











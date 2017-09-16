// =====================================================================================
//
//       Filename:  9085.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/16/2016 22:18:09
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
	int T; cin >> T;
	for(; T--;)
	{
		int N; cin >> N;
		int sum = 0;
		for(int x; N--;)
			cin >> x, sum += x;
		cout << sum << endl;
	}
	return 0;
}











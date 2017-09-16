// =====================================================================================
//
//       Filename:  12790.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 13:00:21
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

#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

int main() {
	int T; cin >> T;
	for(; T--;)
	{
		int A[4];
		for(int i=0; i<4; i++) cin >> A[i];
		for(int x, i=0; i<4; i++) cin >> x, A[i] += x;
		int minA[3] = {1, 1, 0};
		for(int i=0; i<3; i++) A[i] = max(A[i], minA[i]);
		cout << (A[0] + A[1] * 5 + (A[2] + A[3]) * 2) << endl;
	}
	return 0;
}











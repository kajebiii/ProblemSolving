// =====================================================================================
//
//       Filename:  11726.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 17:23:45
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

const int MOD = 1e4 + 7;

int A[1111];

int main() {
	int N; cin >> N;
	A[0] = A[1] = 1;
	for(int i=2; i<=N; i++)
		A[i] = (A[i-1] + A[i-2]) % MOD;
	cout << A[N];
	return 0;
}











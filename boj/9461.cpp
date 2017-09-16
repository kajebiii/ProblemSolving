// =====================================================================================
//
//       Filename:  9461.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 17:06:33
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

long long  P[111];

int main() {
	P[1] = P[2] = P[3] = 1;
	P[4] = P[5] = 2;
	int T; cin >> T;
	for(int i=6; i<=100; i++)
		P[i] = P[i-1] + P[i-5];
	for(int N; T--;)
		cin >> N, cout << P[N] << endl;
	return 0;
}











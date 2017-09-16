// =====================================================================================
//
//       Filename:  11727.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 20:26:54
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

int Dy[1111];

int main() {
	int N; cin >> N;
	Dy[0] = Dy[1] = 1;
	for(int i=2; i<=N; i++)
		Dy[i] = (Dy[i-1] + Dy[i-2] * 2) % MOD;

	cout << Dy[N];
	return 0;
}











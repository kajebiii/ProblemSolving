// =====================================================================================
//
//       Filename:  11057.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 14:30:15
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

using namespace std;

typedef pair<int, int> pi;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};
const int MOD = 10007;

int N, Dy[1111][10];

int main() {
	cin >> N;
	Dy[0][0] = 1;
	for(int i=1; i<=N; i++)
		for(int j=0; j<10; j++) for(int k=0; k<=j; k++)
			Dy[i][j] += Dy[i-1][k], Dy[i][j] %= MOD;
	cout << accumulate(Dy[N], Dy[N]+10, 0) % MOD;
	return 0;
}











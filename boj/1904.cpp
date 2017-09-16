// =====================================================================================
//
//       Filename:  1904.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 14:00:53
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
const int MOD = 15746;
const int MAX_N = 1e6 + 100;

int A[MAX_N];
int main() {
	int N; cin >> N;
	A[0] = A[1] = 1;
	for(int i=2; i<=N; i++)
		A[i] = (A[i-1] + A[i-2]) % MOD;
	cout << A[N];
	return 0;
}











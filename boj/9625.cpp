// =====================================================================================
//
//       Filename:  9625.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/26/2016 13:22:26
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

long long A[50], B[50];
int main() {
	int N; cin >> N;
	A[0] = 1;
	for(int i=1; i<=N; i++)
	{
		A[i] = B[i-1];
		B[i] = A[i-1] + B[i-1];
	}
	int i = N;
	cout << A[i] << ' ' << B[i];
	return 0;
}











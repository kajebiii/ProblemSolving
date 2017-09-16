// =====================================================================================
//
//       Filename:  9507.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 17:44:03
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

int main() {
	int N; cin >> N;
	long long A[68];
	A[0] = A[1] = 1; A[2] = 2; A[3] = 4;
	for(int i=4; i<68; i++)
		A[i] = A[i-1]+A[i-2]+A[i-3]+A[i-4];
	for(; N--;)
	{
		int x; scanf("%d", &x);
		printf("%lld\n", A[x]);
	}
	return 0;
}











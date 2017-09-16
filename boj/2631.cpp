// =====================================================================================
//
//       Filename:  2631.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 19:10:54
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

int A[222], AN;

int main() {
	int N; cin >> N;
	for(int i=0; i<N; i++)
	{
		int x; scanf("%d", &x);
		int index = lower_bound(A, A+AN, x) - A;
		if(index == AN) AN++;
		A[index] = x;
	}
	cout << N - AN;
	return 0;
}











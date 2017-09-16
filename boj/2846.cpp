// =====================================================================================
//
//       Filename:  2846.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 14:26:09
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
const int MAX_N = 1111;

int A[MAX_N], AN, Dy[MAX_N];

int main() {
	int N; cin >> N;
	for(int i=1; i<=N; i++)
		scanf("%d", &A[i]);
	
	int ans = 0;
	for(int i=2; i<=N; i++)
	{
		if(A[i] > A[i-1])
			Dy[i] = Dy[i-1] + A[i] - A[i-1];
		ans = max(Dy[i], ans);
	}
	cout << ans;
	return 0;
}











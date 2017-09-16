// =====================================================================================
//
//       Filename:  10819.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 15:56:18
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

int A[10], N;

int main() {
	cin >> N;
	for(int i=0; i<N; i++) cin >> A[i];
	sort(A, A+N);
	int c[10];
	for(int i=0; i<N; i++) c[i] = i;
	int ans = 0;
	do
	{
		int now = 0;
		for(int i=1; i<N; i++)
			now += abs(A[c[i]] - A[c[i-1]]);
		ans = max(ans, now);
	}while(next_permutation(c, c+N));
	cout << ans;
	return 0;
}











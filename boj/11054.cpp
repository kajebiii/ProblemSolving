// =====================================================================================
//
//       Filename:  11054.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 15:49:32
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

int A[1111], AN;
int Memo[1111], Nr[1111];
int main() {
	int N; cin >> N;
	for(int x,i=0; i<N; i++)
	{
		scanf("%d", &x);
		Nr[N-i-1] = x;
		int index = lower_bound(A, A+AN, x) - A;
		if(index == AN) AN++;
		A[index] = x;
		Memo[N-i-1] = index + 1;
	}
	AN = 0;
	int ans = 0;
	for(int i=0; i<N; i++)
	{
		int x = Nr[i];
		int index = lower_bound(A, A+AN, x) - A;
		if(index == AN) AN++;
		A[index] = x;
		ans = max(ans, Memo[i] + index);
	}
	cout << ans;
	return 0;
}











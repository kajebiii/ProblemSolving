// =====================================================================================
//
//       Filename:  5361.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 12:45:06
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

int main() {
	int A[5] = {35034, 23090, 19055, 12530, 18090};
	int N; cin >> N;
	for(; N--;)
	{
		int ans = 0;
		for(int x, i=0; i<5; i++)
			cin >> x, ans += A[i] * x;
		printf("$%d.%02d\n", ans/100, ans%100);
	}
	return 0;
}











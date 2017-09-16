// =====================================================================================
//
//       Filename:  1547.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 13:13:10
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
	int M; cin >> M;
	int A[4] = {0, 1, 0, 0};
	for(; M--;)
	{
		int x, y; scanf("%d%d", &x, &y);
		swap(A[x], A[y]);
	}
	for(int i=1; i<=3; i++)
		if(A[i]) cout << i;
	return 0;
}











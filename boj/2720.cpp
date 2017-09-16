// =====================================================================================
//
//       Filename:  2720.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/24/2016 21:14:50
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
	int T; cin >> T;
	for(; T--;)
	{
		int x; scanf("%d", &x);
		int C[4] = {25, 10, 5, 1};
		for(int i=0; i<4; i++)
		{
			printf("%d ", x / C[i]);
			x %= C[i];
		}
		puts("");
	}
	return 0;
}











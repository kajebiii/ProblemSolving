// =====================================================================================
//
//       Filename:  2775.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 18:50:56
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

long long How[15][15];

int main() {
	int T; cin >> T;
	for(int i=1; i<=14; i++) How[0][i] = i;
	for(int i=1; i<=14; i++) for(int j=1; j<=14; j++)
		How[i][j] = How[i][j-1] + How[i-1][j];
	for(; T--;)
	{
		int x, y; scanf("%d%d", &x, &y);
		printf("%lld\n", How[x][y]);
	}
	return 0;
}











// =====================================================================================
//
//       Filename:  11660.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/28/2016 00:36:46
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

int N, M;
int Sum[MAX_N][MAX_N];

int main() {
	cin >> N >> M;
	for(int i=1; i<=N; i++) for(int x, j=1; j<=N; j++)	
		scanf("%d", &x), Sum[i][j] = Sum[i-1][j] + Sum[i][j-1] - Sum[i-1][j-1] + x;
	while(M--)
	{
		int a, b, x, y;
		scanf("%d%d%d%d", &a, &b, &x, &y);
		printf("%d\n", Sum[x][y] - Sum[a-1][y] - Sum[x][b-1] + Sum[a-1][b-1]);
	}
	return 0;
}











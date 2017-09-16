// =====================================================================================
//
//       Filename:  11659.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/28/2016 00:32:54
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
const int MAX_N = 1e5 + 100;

int N, M;
int Nr[MAX_N], Sum[MAX_N];

int main() {
	cin >> N >> M;
	for(int i=1; i<=N; i++)
		scanf("%d", &Nr[i]), Sum[i] = Sum[i-1] + Nr[i];
	while(M--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", Sum[y] - Sum[x-1]);
	}
	return 0;
}











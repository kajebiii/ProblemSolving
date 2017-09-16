// =====================================================================================
//
//       Filename:  2669.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 19:04:04
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

int Nr[111][111];

int main() {
	for(int i=0; i<4; i++)
	{
		int x[2], y[2];
		for(int j=0; j<2; j++)
			scanf("%d%d", &x[j], &y[j]);
		for(int i=x[0]; i<x[1]; i++) for(int j=y[0]; j<y[1]; j++)
			Nr[i][j] = 1;
	}
	cout << accumulate(&Nr[0][0], &Nr[112][0], 0);
	return 0;
}











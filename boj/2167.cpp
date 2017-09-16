// =====================================================================================
//
//       Filename:  2167.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 20:37:18
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

using namespace std;

const int MAX_N = 500;

int N, M, Nr[MAX_N][MAX_N];
int Sum[MAX_N][MAX_N];

int main() {
	cin >> N >> M;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) 
		cin >> Nr[i][j], Sum[i][j] = Sum[i-1][j] + Sum[i][j-1] - Sum[i-1][j-1] + Nr[i][j];
	int T; cin >> T;
	for(; T--;)
	{
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		printf("%d\n", Sum[x][y] - Sum[x][j-1] - Sum[i-1][y] + Sum[i-1][j-1]);
	}
	return 0;
}






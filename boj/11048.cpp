// =====================================================================================
//
//       Filename:  11048.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/21/2016 17:21:40
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

const int MAX_N = 1111;

int Dy[MAX_N][MAX_N];

int main() {
	int N, M; scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
	{
		int x; scanf("%d", &x);
		Dy[i][j] = max(Dy[i-1][j], Dy[i][j-1]) + x;
	}
	cout << Dy[N][M];
	return 0;
}











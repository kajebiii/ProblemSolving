// =====================================================================================
//
//       Filename:  9465.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 17:42:58
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

#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

const int MAX_N = 1e5 + 10;

int Nr[2][MAX_N];
int Dy[3][MAX_N];

int main() {
	int T; cin >> T;
	for(; T--;)
	{
		int N; cin >> N;
		for(int j=0; j<2; j++)
			for(int i=1; i<=N; i++)
				scanf("%d", &Nr[j][i]);
		for(int j=0; j<3; j++)
			for(int i=0; i<MAX_N; i++)
				Dy[j][i] = 0;
		for(int i=1; i<=N; i++)
		{
			Dy[0][i] = max(Dy[1][i-1], Dy[2][i-1]) + Nr[0][i];
			Dy[1][i] = max(Dy[0][i-1], Dy[2][i-1]) + Nr[1][i];
			Dy[2][i] = max(Dy[2][i-1], max(Dy[0][i-1], Dy[1][i-1]));
		}
		printf("%d\n", max(Dy[0][N], max(Dy[1][N], Dy[2][N])));
	}
	return 0;
}











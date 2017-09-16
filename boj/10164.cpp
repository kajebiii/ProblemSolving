// =====================================================================================
//
//       Filename:  10164.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 15:37:16
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

int Cnt[20][20];

int main() {
	int N, M, K; cin >> N >> M >> K;
	Cnt[0][1] = 1;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
		Cnt[i][j] = Cnt[i-1][j] + Cnt[i][j-1];
	if(K == 0)
		cout << Cnt[N][M] << endl;
	else
	{
		int A = (K-1) / M + 1, B = (K-1) % M + 1;
		cout << Cnt[A][B] * Cnt[N-A+1][M-B+1];
	}
	return 0;
}











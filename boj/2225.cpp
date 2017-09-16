// =====================================================================================
//
//       Filename:  2225.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 17:28:55
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
#include <math.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};
const int MAX_N = 222;
const int MOD = 1000000000;

int N, K;
int Dy[222][222];

int main() {
	Dy[0][0] = 1;
	cin >> N >> K;
	int Ans = 0;
	for(int i=1; i<=K; i++)
	{
		for(int j=1; j<=N; j++)
			for(int k=j; k>=0; k--)
				Dy[i][j] = (Dy[i][j] + Dy[i-1][k]) % MOD;
		Ans += Dy[i][N];
		Ans %= MOD;
	}
	cout << Ans;
	return 0;
}











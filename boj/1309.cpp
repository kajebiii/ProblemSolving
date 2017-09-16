// =====================================================================================
//
//       Filename:  1309.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 17:49:09
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
const int MAX_N = 1e5 + 10;
const int MOD = 9901;

int Dy[MAX_N][4];

int main() {
	Dy[0][0] = 1;
	int N; cin >> N;
	for(int i=1; i<=N; i++)
	{
		for(int j=0; j<3; j++)
			for(int k=0; k<3; k++)
				if((j & k) == 0)
					Dy[i][j] += Dy[i-1][k], Dy[i][j] %= MOD;
	}
	int result = accumulate(Dy[N], Dy[N] + 4, 0);
	result %= MOD;
	cout << result;
	return 0;
}











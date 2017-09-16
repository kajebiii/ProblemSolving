// =====================================================================================
//
//       Filename:  1562.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 21:46:42
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
#define pb push_back
#define fi first
#define se second
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MOD = 1e9;

int Dy[1<<10][11][111], N;
int main() {
	cin >> N;
	for(int i=1; i<10; i++) Dy[1<<i][i][1] = 1;
	for(int i=2; i<=N; i++)
	{
		for(int j=0; j<9; j++)
			for(int k=0; k<1<<10; k++)
				Dy[k|1<<j][j][i] = (Dy[k|1<<j][j][i] + Dy[k][j+1][i-1]) % MOD;
		for(int j=1; j<10; j++)
			for(int k=0; k<1<<10; k++)
				Dy[k|1<<j][j][i] = (Dy[k|1<<j][j][i] + Dy[k][j-1][i-1]) % MOD;
	}
	int Ans = 0;
	for(int i=0; i<10; i++)
		Ans = (Ans + Dy[-1+(1<<10)][i][N]) % MOD;
	cout << Ans;
	return 0;
}











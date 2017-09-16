// =====================================================================================
//
//       Filename:  1563.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/09/2016 10:11:45
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
const int MOD = 1e6;

int Dy[1111][2][3], N;
int main() {
	Dy[0][0][0] = 1;
	cin >> N;
	for(int i=1; i<=N; i++)
	{
		for(int j=0; j<2; j++)
			for(int k=0; k<3; k++)
				Dy[i][j][0] = (Dy[i][j][0] + Dy[i-1][j][k]) % MOD;
		for(int k=0; k<3; k++)
			Dy[i][1][0] = (Dy[i][1][0] + Dy[i-1][0][k]) % MOD;
		for(int j=0; j<2; j++)
			for(int k=1; k<3; k++)
				Dy[i][j][k] = (Dy[i][j][k] + Dy[i-1][j][k-1]) % MOD;
	}
	int ans = 0;
	for(int j=0; j<2; j++) for(int k=0; k<3; k++) ans = (ans + Dy[N][j][k]) % MOD;
	cout << ans;
	return 0;
}





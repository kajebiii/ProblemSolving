// =====================================================================================
//
//       Filename:  5002.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/24/2016 16:05:32
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
#include <assert.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int X, N, Dy[222][3][111];
string S; map<char, int> M;
int main() {
	cin >> X >> S; N = S.length(); M['M'] = -1; M['W'] = 1;
	for(int l=0; l<222; l++) for(int i=0; i<3; i++) for(int j=0; j<111; j++)
		Dy[l][i][j] = -INF;
	S.pb('M');
	Dy[100][M[S[0]] + 1][1] = 0;
	Dy[100 + M[S[0]]][M[S[1]] + 1][2] = 1;
	for(int i=1; i<=N; i++)
		for(int l=100-X; l<=100+X; l++)
			for(int j=0; j<3; j+=2)
			{
				if(Dy[l][j][i] == -INF) continue;
				int nl, nj, ni;
				nl = l + (j-1); nj = M[S[i]] + 1; ni = i+1;
				if(abs(100 - nl) <= X) Dy[nl][nj][ni] = max(Dy[nl][nj][ni], Dy[l][j][i] + 1);
				if(i == N) continue;
				nl = l + M[S[i]]; nj = j; ni = i+1;
				if(abs(100 - nl) <= X) Dy[nl][nj][ni] = max(Dy[nl][nj][ni], Dy[l][j][i] + 1);
			}
	int ans = 0;
	for(int l=100-X; l<=100+X; l++) for(int j=0; j<3; j+=2) for(int i=1; i<=N+1; i++)
		ans = max(ans, Dy[l][j][i]);
	cout << ans;
	return 0;
}











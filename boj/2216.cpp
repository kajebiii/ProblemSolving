// =====================================================================================
//
//       Filename:  2216.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 14:01:13
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
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int Dy[3333][3333], XN, YN, A, B, C;
char X[3333], Y[3333];
int main() {
	cin >> A >> B >> C; scanf("%s%s", X+1, Y+1);
	XN = (int)strlen(X+1), YN = (int)strlen(Y+1);
	for(int i=1; i<=XN; i++) Dy[i][0] = B*i;
	for(int i=1; i<=YN; i++) Dy[0][i] = B*i;
	for(int i=1; i<=XN; i++) for(int j=1; j<=YN; j++)
	{
		Dy[i][j] = max(Dy[i-1][j] + B, Dy[i][j-1] + B);
		Dy[i][j] = max(Dy[i][j], Dy[i-1][j-1] + C);
		if(X[i] == Y[j])
			Dy[i][j] = max(Dy[i][j], Dy[i-1][j-1] + A);
	}
	cout << Dy[XN][YN];
	return 0;
}











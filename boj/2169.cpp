// =====================================================================================
//
//       Filename:  2169.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/07/2016 09:53:19
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

int N, M, Nr[1111][1111], Dy[1111][1111];
int Now[1111][2];
int main() {
	cin >> N >> M;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) scanf("%d", &Nr[i][j]);
	for(int i=2; i<=M; i++) Dy[0][i] = -INF/2;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++) Now[j][0] = Now[j][1] = Dy[i-1][j] + Nr[i][j];
		for(int j=2; j<=M; j++) Now[j][0] = max(Now[j][0], Now[j-1][0] + Nr[i][j]);
		for(int j=M-1; j>=1; j--) Now[j][1] = max(Now[j][1], Now[j+1][1] + Nr[i][j]);
		for(int j=1; j<=M; j++) Dy[i][j] = max(Now[j][0], Now[j][1]);
	}
	cout << Dy[N][M];
	return 0;
}











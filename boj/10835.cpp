// =====================================================================================
//
//       Filename:  10835.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 18:06:25
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
const int MAX_N = 2222;

int A[MAX_N], B[MAX_N], N;
int Dy[MAX_N][MAX_N];

int main() {
	cin >> N;
	for(int i=1; i<=N; i++) scanf("%d", &A[i]);
	for(int i=1; i<=N; i++) scanf("%d", &B[i]);
	for(int i=1; i<=N+1; i++) for(int j=1; j<=N+1; j++) Dy[i][j] = -INF;
	Dy[1][1] = 0;
	for(int i=1; i<=N+1; i++) for(int j=1; j<=N+1; j++)
	{
		if(i-1 > 0 && j-1 > 0) Dy[i][j] = max(Dy[i][j], Dy[i-1][j-1]);
		if(i-1 > 0) Dy[i][j] = max(Dy[i][j], Dy[i-1][j]);
		if(j-1 > 0 && A[i] > B[j-1]) Dy[i][j] = max(Dy[i][j], Dy[i][j-1] + B[j-1]);
	}
	int ans = -INF;
	for(int i=1; i<=N+1; i++)
		ans = max(ans, Dy[i][N+1]),
		ans = max(ans, Dy[N+1][i]);
	cout << ans;
	return 0;
}











// =====================================================================================
//
//       Filename:  2666.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 02:24:14
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

int Dy[30][30][30];
int main() {
	int M; cin >> M;
	int A, B; cin >> A >> B;
	int N; cin >> N;
	for(int n=0; n<=N; n++) for(int i=1; i<=M; i++) for(int j=1; j<=M; j++)
		Dy[n][i][j] = INF;
	Dy[0][A][B] = 0;
	for(int n=1; n<=N; n++)
	{
		int x; scanf("%d", &x);
		for(int i=1; i<=M; i++)
			for(int j=1; j<=M; j++)
				if(Dy[n-1][i][j] != INF)
				{
					Dy[n][x][j] = min(Dy[n][x][j], Dy[n-1][i][j] + abs(i-x));
					Dy[n][i][x] = min(Dy[n][i][x], Dy[n-1][i][j] + abs(j-x));
				}
	}
	int ans = INF;
	for(int i=1; i<=M; i++) for(int j=1; j<=M; j++) ans = min(ans, Dy[N][i][j]);
	cout << ans;
	return 0;
}











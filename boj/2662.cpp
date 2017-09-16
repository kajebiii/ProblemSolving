// =====================================================================================
//
//       Filename:  2662.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/12/2016 17:47:43
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
const int MAX_N = 333, MAX_K = 22;

int N, K, Dy[MAX_K][MAX_N], W[MAX_K][MAX_N], Get[MAX_K][MAX_N];
void printAns(int k, int n)
{
	if(k == 0) return;
	printAns(k-1, n - W[k][n]);
	printf("%d ", W[k][n]);
}
int main() {
	cin >> N >> K;
	for(int i=1; i<=N; i++)
	{
		int m; scanf("%d", &m);
		for(int j=1; j<=K; j++)
		{
			int x; scanf("%d", &x);
			Get[j][m] = x;
		}
	}
	for(int i=0; i<=K; i++) for(int j=0; j<=N; j++) Dy[i][j] = -INF;
	Dy[0][0] = 0;
	for(int i=1; i<=K; i++) for(int j=0; j<=N; j++) for(int k=0; k<=j; k++)
		if(Dy[i][j] < Dy[i-1][k] + Get[i][j-k])
		{
			Dy[i][j] = max(Dy[i][j], Dy[i-1][k] + Get[i][j-k]);
			W[i][j] = j-k;
		}
	cout << Dy[K][N] << endl;
	printAns(K, N);
	return 0;
}











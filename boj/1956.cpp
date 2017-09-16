// =====================================================================================
//
//       Filename:  1956.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 02:39:37
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
const int MAX_N = 444;

int V[MAX_N][MAX_N];
int N, M;

int main() {	
	cin >> N >> M;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) V[i][j] = INF;
	while(M--)
	{
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		V[a][b] = min(V[a][b], c);
	}
	for(int k=1; k<=N; k++) for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(V[i][k] != INF && V[k][j] != INF)
			V[i][j] = min(V[i][j], V[i][k] + V[k][j]);
	int Ans = INF;
	for(int i=1; i<=N; i++) Ans = min(Ans, V[i][i]);
	if(Ans == INF) Ans = -1;
	printf("%d\n", Ans);
	return 0;
}











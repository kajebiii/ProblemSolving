// =====================================================================================
//
//       Filename:  11062.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/12/2016 10:20:33
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
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MAX_N = 1111;

int N, Nr[MAX_N], Dy[MAX_N][MAX_N], Sum[MAX_N];
int getMax(int a, int b)
{
	if(Dy[a][b] != INF) return Dy[a][b];
	if(a == b) return Nr[a];
	int result = max(Nr[a] + Sum[b  ] - Sum[a  ] - getMax(a+1, b)
			       , Nr[b] + Sum[b-1] - Sum[a-1] - getMax(a, b-1));
	Dy[a][b] = result;
	return result;
}
int main() {
	int T; cin >> T;
	while(T--)
	{
		scanf("%d", &N); 
		for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
		for(int i=1; i<=N; i++) Sum[i] = Sum[i-1] + Nr[i];
		for(int i=1; i<=N; i++) for(int j=i; j<=N; j++) Dy[i][j] = INF;
		printf("%d\n", getMax(1, N));
	}
	return 0;
}











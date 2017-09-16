// =====================================================================================
//
//       Filename:  2357.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 20:50:42
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
const int MAX_N = 111111;

int N, M, T[MAX_N*4][2], P;

pi get(int a, int b)
{
	pi r = mp(0, INF);
	while(a<=b)
	{
		if(  a%2) r.fi = max(r.fi, T[a][0]), r.se = min(r.se, T[a][1]), a++;
		if(1-b%2) r.fi = max(r.fi, T[b][0]), r.se = min(r.se, T[b][1]), b--;
		a /= 2; b /= 2;
	}
	return r;
}

int main() {
	cin >> N >> M;
	for(P=1; P<N; P<<=1);
	for(int i=0; i<N; i++) scanf("%d", &T[P+i][0]), T[P+i][1] = T[P+i][0];
	for(int i=N; i<P; i++) T[P+i][1] = INF;
	for(int i=P-1; i>=1; i--)
		T[i][0] = max(T[i*2][0], T[i*2+1][0]),
		T[i][1] = min(T[i*2][1], T[i*2+1][1]);
	while(M--)
	{
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		pi ans = get(P+a, P+b);
		printf("%d %d\n", ans.se, ans.fi);
	}
	return 0;
}











// =====================================================================================
//
//       Filename:  11060.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 20:20:25
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
const int MAX_N = 1111;

int N, Dy[MAX_N];

int main() {
	cin >> N;
	for(int i=2; i<=N; i++) Dy[i] = INF;
	for(int i=1; i<=N; i++)
	{
		int y; scanf("%d", &y);
		if(Dy[i] == INF) continue;
		for(int x=1; x<=y; x++)
			Dy[i+x] = min(Dy[i+x], Dy[i]+1);
	}
	if(Dy[N] == INF) Dy[N] = -1;
	cout << Dy[N];
	return 0;
}











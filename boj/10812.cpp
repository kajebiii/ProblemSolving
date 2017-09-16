// =====================================================================================
//
//       Filename:  10812.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 14:56:12
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

int Ans[111][111];
int main() {
	int N, M; cin >> N >> M;
	for(int i=1; i<=N; i++) Ans[M][i] = i;
	while(M--)
	{
		int a, m, b; scanf("%d%d%d", &a, &b, &m);
		for(int i=1; i<=N; i++) Ans[M][i] = Ans[M+1][i];
		for(int i=a; i<=b; i++) Ans[M][i] = Ans[M+1][(i-a+m-a)%(b-a+1)+a];
	}
	for(int i=1; i<=N; i++) printf("%d ", Ans[0][i]);
	return 0;
}











// =====================================================================================
//
//       Filename:  1495.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 00:01:21
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

int N, S, M;
bool Dy[111][1111];

int main() {
	cin >> N >> S >> M;
	Dy[0][S] = true;
	for(int i=1; i<=N; i++)
	{
		int x; scanf("%d", &x);
		for(int j=x; j<=M; j++)
			Dy[i][j] |= Dy[i-1][j-x];
		for(int j=0; j<=M-x; j++)
			Dy[i][j] |= Dy[i-1][j+x];
	}
	for(int i=M; i>=0; i--)
		if(Dy[N][i])
		{
			printf("%d\n", i);
			return 0;
		}
	puts("-1");
	return 0;
}











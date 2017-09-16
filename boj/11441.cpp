// =====================================================================================
//
//       Filename:  11441.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 15:11:53
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

int N, Sum[111111], M;
int main() {
	cin >> N; for(int x, i=1; i<=N; i++) scanf("%d", &x), Sum[i] = Sum[i-1] + x;
	cin >> M;
	while(M--)
	{
		int a, b; scanf("%d%d", &a, &b);
		printf("%d\n", Sum[b] - Sum[a-1]);
	}
	return 0;
}











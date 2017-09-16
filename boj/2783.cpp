// =====================================================================================
//
//       Filename:  2783.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 22:34:35
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

struct DATA
{
	int x, y;
	const bool operator<(const DATA &o) const
	{
		return x*o.y < o.x*y;
	}
}Ans, Now;
int main() {
	scanf("%d%d", &Ans.x, &Ans.y);
	int N; cin >> N;
	while(N--)
	{
		scanf("%d%d", &Now.x, &Now.y);
		if(Now < Ans) Ans = Now;
	}
	printf("%.2lf", (double)1000.0/Ans.y*Ans.x);
	return 0;
}











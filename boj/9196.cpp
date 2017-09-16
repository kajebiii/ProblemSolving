// =====================================================================================
//
//       Filename:  9196.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/02/2016 22:18:33
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

struct RECT
{
	int h, w;
	const bool operator<(const RECT &o) const
	{
		int me = h*h + w*w;
		int other = o.h*o.h + o.w*o.w;
		if(me == other) return h < o.h;
		return me < other;
	}
};

int main() {
	RECT R;
	while(1)
	{
		scanf("%d%d", &R.h, &R.w);
		if(R.h == 0 && R.w == 0) break;
		RECT Ans; Ans.h = 300; Ans.w = 300;
		for(int i=1; i<=200; i++) for(int j=i+1; j<=200; j++)
		{
			RECT now; now.h = i; now.w = j;
			if(R < now && now < Ans) Ans = now;
		}
		printf("%d %d\n", Ans.h, Ans.w);
	}
	return 0;
}











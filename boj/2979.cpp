// =====================================================================================
//
//       Filename:  2979.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 01:17:12
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

int Cnt[111];
int main() {
	int A[4]={0}; for(int i=1; i<=3; i++) scanf("%d", &A[i]);
	for(int i=0; i<3; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		Cnt[x]++;
		Cnt[y]--;
	}

	int now = 0, ans = 0;
	for(int i=0; i<=110; i++)
	{
		now += Cnt[i];
		ans += A[now] * now;
	}
	cout << ans;
	return 0;
}











// =====================================================================================
//
//       Filename:  2052.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/02/2016 12:47:04
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

int main() {
	int N; cin >> N;
	vector<int> ans; ans.pb(1);
	for(int i=1; i<=N; i++)
	{
		vector<int> now;
		int val = 0;
		for(int x : ans)
		{
			val += x;
			now.pb(val/2);
			val %= 2;
			val *= 10;
		}
		now.pb(val/2);

		now.swap(ans);
	}
	bool flag = true;
	for(int x : ans)
	{
		printf("%d", x);
		if(flag) printf(".");
		flag = false;
	}
	return 0;
}











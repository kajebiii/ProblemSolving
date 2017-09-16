// =====================================================================================
//
//       Filename:  1105.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/10/2016 20:27:25
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

int L, R;
int main() {
	cin >> L >> R;
	int power = 1000000000, cnt = 0;
	bool flag = false;
	while(power)
	{
		int l = L / power; L %= power;
		int r = R / power; R %= power;
		if(l < r) {printf("%d", cnt); flag = true; break;}
		if(l == 8) cnt++;
		power /= 10;
	}
	if(flag == false) printf("%d", cnt);
	return 0;
}











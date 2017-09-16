// =====================================================================================
//
//       Filename:  1527.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 19:46:57
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
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

vector<int> V;
int main() {
	int A, B; cin >> A >> B;
	for(int p=1; p<=9; p++)
		for(int i=0; i<1<<p; i++)
		{
			int now = 0;
			for(int j=0; j<p; j++)
			{
				now *= 10;
				now += (i & 1<<j)?7:4;
			}
			V.pb(now);
		}
	int ans = 0;
	for(int x : V) if(A <= x && x <= B) ans++;
	cout << ans;
	return 0;
}











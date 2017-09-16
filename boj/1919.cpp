// =====================================================================================
//
//       Filename:  1919.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 15:50:07
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

int CntA[333];
int CntB[333];
int main() {
	string A; cin >> A; for(char x : A) CntA[x]++;
	string B; cin >> B; for(char x : B) CntB[x]++;

	int ans = 0;
	for(int i=0; i<333; i++)
		ans += abs(CntA[i] - CntB[i]);
	cout << ans;
	return 0;
}











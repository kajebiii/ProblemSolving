// =====================================================================================
//
//       Filename:  11652.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 00:00:58
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

map<ll, int> M;
int main() {
	int N; cin >> N;
	while(N--)
	{
		ll x; scanf("%lld", &x);
		if(M.count(x) == 0) M[x] = 1;
		else M[x]++;
	}

	int ansV = -1; ll ans = -1;
	for(pair<ll, int> x : M)
		if(ansV < x.se) {ansV = x.se; ans = x.fi;}
	cout << ans;
	return 0;
}











// =====================================================================================
//
//       Filename:  11947.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 21:08:20
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

ll getR(ll n, ll p) {return n?(9-n%10)*p+getR(n/10, p*10):0;}
int main() {
	int T; cin >> T;
	while(T--)
	{
		ll N; cin >> N;
		ll Ans = 1ll * N * getR(N, 1);
		for(ll p=5; (p-1)<=N; p*=10) Ans = max(Ans, (p-1)*getR(p-1, 1));
		printf("%lld\n", Ans);
	}
	return 0;
}











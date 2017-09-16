// =====================================================================================
//
//       Filename:  2399.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 15:13:52
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

int N;
ll Nr[11111], Sum[11111];
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%lld", &Nr[i]);
	sort(Nr, Nr+N);
	for(int i=N-1; i>=0; i--) Sum[i] = Sum[i+1] + 1ll*Nr[i];
	ll ans = 0;
	for(int i=0; i<N; i++)
		ans += Sum[i+1] - 1ll*(N-i-1)*Nr[i];
	cout << ans*2;
	return 0;
}











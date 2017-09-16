// =====================================================================================
//
//       Filename:  1234.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/26/2016 13:06:01
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
#include <assert.h>

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

ll N, Nr[3], Fac[11], Ans;
void getAns(ll n, ll *nr, ll ans)
{
	bool isOK = true;
	for(int i=0; i<3; i++) if(nr[i] < 0) isOK = false; if(!isOK) return;
	if(n > N)
	{
		int sum = accumulate(nr, nr+3, 0);
		Ans += ans;
		return;
	}
	for(int i=0; i<3; i++) {nr[i] -= n; getAns(n+1, nr, ans); nr[i] += n;}
	if(n % 2 == 0) for(int i=0; i<3; i++)
	{
		nr[(i+1)%3] -= n/2; nr[(i+2)%3] -= n/2;
		getAns(n+1, nr, ans * (Fac[n] / Fac[n/2] / Fac[n/2]));
		nr[(i+1)%3] += n/2; nr[(i+2)%3] += n/2;
	}
	if(n % 3 == 0)
	{
		for(int i=0; i<3; i++) nr[i] -= n/3;
		getAns(n+1, nr, ans * (Fac[n] / Fac[n/3] / Fac[n/3] / Fac[n/3]));
		for(int i=0; i<3; i++) nr[i] += n/3;
	}
}
int main() {
	cin >> N; for(int i=0; i<3; i++) cin >> Nr[i];
	Fac[0] = 1; for(int i=1; i<=N; i++) Fac[i] = Fac[i-1] * i;
	getAns(1, Nr, 1ll);
	cout << Ans;
	return 0;
}











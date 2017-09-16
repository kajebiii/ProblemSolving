// =====================================================================================
//
//       Filename:  1722.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/19/2016 09:39:54
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

int N, Nr[22], Chk[22]; ll K, Fac[22];
int main() {
	cin >> N; int type; cin >> type;
	Fac[0] = 1; for(int i=1; i<=N; i++) Fac[i] = Fac[i-1] * i;
	assert(type <= 2);
	if(type == 1)
	{
		cin >> K; K--;
		for(int i=1; i<=N; i++)
			for(int k=1; k<=N; k++)
			{
				if(Chk[k] == 1) continue;
				if(K >= Fac[N-i]) K -= Fac[N-i];
				else {Nr[i] = k, Chk[k] = 1; break;}
			}
		for(int i=1; i<=N; i++) printf("%d ", Nr[i]);
	}
	else if(type == 2)
	{
		ll ans = 0;
		for(int i=1; i<=N; i++) cin >> Nr[i];
		for(int i=1; i<=N; i++)
			for(int k=1; k<=N; k++)
			{
				if(Chk[k] == 1) continue;
				if(k == Nr[i]) {Chk[Nr[i]] = 1; break;} 
				ans += Fac[N-i];
			}
		cout << ans + 1;
	}
	return 0;
}











// =====================================================================================
//
//       Filename:  2089.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/02/2016 21:26:19
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

ll Block[55][2];
bool isIn(ll k, int i) {return Block[i][0] <= k && k <= Block[i][1];}
int main() {
	ll N; cin >> N;
	Block[0][0] = Block[0][1] = 0;
	for(ll i=1, power=1; i<=41; i++, power *= -2)
	{
		for(int j=0; j<2; j++) Block[i][j] = Block[i-1][j];
		Block[i][i%2] += power;
	}
	bool first = false;
	ll firstPower = 1; for(int i=0; i<40; i++) firstPower *= -2;
	for(ll i=40, power = firstPower; i>=0; i--, power /= -2)
	{
		int now = (!isIn(N, i) && isIn(N, i+1));
		if(now == 1) first = true, N -= power;
		if(first) printf("%d", now);
	}
	if(first == false) printf("0");
	return 0;
}











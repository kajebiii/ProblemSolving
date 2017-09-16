// =====================================================================================
//
//       Filename:  10258.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 20:57:03
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

int N, Nr[33];
int getC(int n)
{
	if(n == 0) return Nr[n];
	int r = 0;
	if(Nr[n] == 1) r = 1<<n, Nr[n-1] = 1 - Nr[n-1];
	return r + getC(n-1);
}
int main() {
	int T; cin >> T;
	while(T--)
	{
		for(int i=0; i<31; i++) Nr[i] = 0;
		string S; cin >> S; int N = S.length();
		for(int i=0; i<N; i++) Nr[i] = S[i] - '0';
		reverse(Nr, Nr+N);
		printf("%d\n", getC(30));
	}
	return 0;
}











// =====================================================================================
//
//       Filename:  5893.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/15/2016 17:48:36
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

int A[1500];
int main() {
	string S; cin >> S;
	for(int i=S.length()-1; i>=0; i--) A[S.length()-1-i] = S[i] - '0';
	for(int i=1200; i>=0; i--) A[i+4] += A[i];
	for(int i=0; i<1500; i++) A[i+1] += A[i]/2, A[i]%=2;
	bool first = false;
	for(int i=1499; i>=0; i--)
	{
		if(A[i] == 1) first = true;
		if(first) printf("%d", A[i]);
	}
	return 0;
}











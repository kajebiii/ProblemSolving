// =====================================================================================
//
//       Filename:  1672.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 12:57:05
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

int C[99][99];
int main() {
	int N; string S; cin >> N >> S;
	C['A']['A'] = 'A'; C['G']['G'] = 'G'; C['C']['C'] = 'C'; C['T']['T'] = 'T';
	C['A']['G'] = C['G']['A'] = 'C'; C['A']['C'] = C['C']['A'] = 'A';
	C['A']['T'] = C['T']['A'] = 'G'; C['G']['C'] = C['C']['G'] = 'T';
	C['G']['T'] = C['T']['G'] = 'A'; C['C']['T'] = C['T']['C'] = 'G';
	for(int i=N-2; i>=0; i--)
		S[i] = C[S[i]][S[i+1]];
	cout << S[0];
	return 0;
}











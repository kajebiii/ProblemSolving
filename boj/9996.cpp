// =====================================================================================
//
//       Filename:  9996.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/10/2016 22:09:40
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
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int main() {
	int N; cin >> N; string S, L, R; cin >> S;
	for(int i=0; i<S.length(); i++)
		if(S[i] == '*')
		{
			L = S.substr(0, i);
			R = S.substr(i+1, S.length() - i - 1);
		}
	while(N--)
	{
		cin >> S;
		if(S.length() < L.length() + R.length()) {printf("NE\n"); continue;}
		string SL = S.substr(0, L.length());
		string SR = S.substr(S.length() - R.length(), R.length());
		if(SL == L && SR == R) puts("DA");
		else puts("NE");
	}
	return 0;
}











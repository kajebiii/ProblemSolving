// =====================================================================================
//
//       Filename:  7600.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  10/04/2016 16:57:09
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
const pi Ch[8] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1), mp(-1, -1), mp(-1, 1), mp(1, -1), mp(1, 1)};

int Chk[50];
string S;
int main() {
	while(getline(cin, S))
	{
		if(S[0] == '#' && S.length() == 1) break;
		for(char &x : S) if(x >= 'a' && x <= 'z') x += 'A' - 'a';
		for(int i=0; i<26; i++) Chk[i] = 0;
		for(char &x : S) if(x >= 'A' && x <= 'Z') Chk[x - 'A'] = 1;
		int ans = 0;
		for(int i=0; i<26; i++) ans += Chk[i];
		printf("%d\n", ans);
	}
	return 0;
}











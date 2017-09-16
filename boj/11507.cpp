// =====================================================================================
//
//       Filename:  11507.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/24/2016 15:34:44
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

map<string, int> M;
int Chk[13*4], Cnt[4];
int main() {
	string S; cin >> S;
	char C[4] = {'P', 'K', 'H', 'T'}; int cnt = 0;
	for(int i=0; i<4; i++) for(int j=1; j<=13; j++)
	{
		string K = ""; K.pb(C[i]); K.pb(j/10 + '0'); K.pb(j%10 + '0');
		M[K] = cnt++;
	}
	int N = S.length();
	bool same = false;
	for(int i=0; i<N; i+=3)
	{
		string now = S.substr(i, 3);
		if(Chk[M[now]]++ == 1) same = true;
		Cnt[M[now]/13]++;
	}
	if(same) puts("GRESKA");
	else for(int i=0; i<4; i++) printf("%d ", 13-Cnt[i]);
	return 0;
}











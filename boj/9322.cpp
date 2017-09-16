// =====================================================================================
//
//       Filename:  9322.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/19/2016 12:10:59
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

int N, Idx[1111];
string St[1111];
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		scanf("%d", &N);
		map<string, int> M;
		for(int i=0; i<N; i++) 
		{
			string S; cin >> S;
			M[S] = i;
		}
		for(int i=0; i<N; i++)
		{
			string S; cin >> S;
			Idx[M[S]] = i;
		}
		for(int i=0; i<N; i++) cin >> St[i];
		for(int i=0; i<N; i++) cout << St[Idx[i]] << " "; puts("");
	}
	return 0;
}











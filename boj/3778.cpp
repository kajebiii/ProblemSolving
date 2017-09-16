// =====================================================================================
//
//       Filename:  3778.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  10/04/2016 17:01:30
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

int Cnt[26];
char A[222], B[222];
int main() {
	int TC; scanf("%d\n", &TC);
	for(int t=1; t<=TC; t++)
	{
		fgets(A, 222, stdin);
		fgets(B, 222, stdin);
		for(int i=0; i<26; i++) Cnt[i] = 0;
		for(int i=0; A[i] != 0 && A[i] != '\n'; i++) Cnt[A[i] - 'a']++;
		for(int i=0; B[i] != 0 && B[i] != '\n'; i++) Cnt[B[i] - 'a']--;
		int ans = 0;
		for(int i=0; i<26; i++) ans += abs(Cnt[i]);
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}











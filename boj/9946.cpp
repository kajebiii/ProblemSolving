// =====================================================================================
//
//       Filename:  9946.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/12/2016 13:13:18
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

int Cnt[26];
int main() {
	int T = 0;
	while(++T)
	{
		string A, B; cin >> A >> B;
		if(A == "END") break;
		for(int i=0; i<26; i++) Cnt[i] = 0;
		for(char x : A) Cnt[x-'a']++;
		for(char x : B) Cnt[x-'a']--;
		bool isTrue = true;
		for(int i=0; i<26; i++) if(Cnt[i] != 0) isTrue = false;
		printf("Case %d: ", T);
		if(isTrue) puts("same");
		else puts("different");
	} 
	return 0;
}











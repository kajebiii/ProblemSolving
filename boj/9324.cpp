// =====================================================================================
//
//       Filename:  9324.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/15/2016 00:35:55
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

int Cnt[26];
char S[101101];
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		scanf("%s", S); int N = (int)strlen(S);
		for(int i=0; i<26; i++) Cnt[i] = 0;

		bool flag = true;
		for(int i=0; i<N; i++)
			if(++Cnt[S[i]-'A'] % 3 == 0)
				if(i+1 < N && S[i+1] == S[i]) i++;
				else{flag = false; break;}
		if(flag) puts("OK");
		else puts("FAKE");
	}
	return 0;
}











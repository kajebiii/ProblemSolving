// =====================================================================================
//
//       Filename:  5704.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 01:03:09
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
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int Cnt[33];

int main() {
	while(1)
	{
		char C[222];
		fgets(C, 222, stdin);
		if(C[0] == '*') break;
		for(int i=0; i<26; i++) Cnt[i] = 0;
		for(int i=0; C[i]; i++)
			if(C[i] >= 'a') Cnt[C[i]-'a']++;
		bool flag = true;
		for(int i=0; i<26; i++) if(Cnt[i] == 0) flag = false;
		printf("%c\n", flag?'Y':'N');
	}
	return 0;
}











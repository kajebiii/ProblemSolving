// =====================================================================================
//
//       Filename:  5698.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/15/2016 18:14:27
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

char S[1111];
char lower(char k) {return k>='a'?k-'a'+'A':k;}
int main() {
	while(1)
	{
		fgets(S, 1111, stdin);
		char x = lower(S[0]);
		if(x == '*') break;
		bool flag = true;
		for(int i=0; S[i]; i++)
			if(S[i] == ' ' && x != lower(S[i+1]))
				flag = false;
		printf("%c\n", flag?'Y':'N');
	}
	return 0;
}











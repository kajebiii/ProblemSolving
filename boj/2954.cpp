// =====================================================================================
//
//       Filename:  2954.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 15:07:30
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

int Chk[999];
int main() {
	string S; getline(cin, S);
	Chk['a'] = Chk['e'] = Chk['i'] = Chk['o'] = Chk['u'] = 1;
	for(int i=0; i<S.length(); i++)
	{
		printf("%c", S[i]);
		if(i < S.length()-2 && S[i] == S[i+2] && S[i+1] == 'p' && Chk[S[i]] == 1)
			i += 2;
	}
	return 0;
}











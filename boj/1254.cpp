// =====================================================================================
//
//       Filename:  1254.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 17:10:02
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

int main() {
	string S, RS; cin >> S; RS = S; reverse(RS.begin(), RS.end());
	for(int i=0; i<S.length(); i++)
	{
		bool flag = true;
		for(int j=0; i+j<S.length(); j++)
			if(S[i+j] != RS[j]) flag = false;
		if(flag) {printf("%d", (int)S.length()+i); break;}
	}
	return 0;
}











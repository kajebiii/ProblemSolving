// =====================================================================================
//
//       Filename:  5656.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 22:49:33
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

string K[2] = {"false", "true"};
int main() {
	for(int t=1; ; t++)
	{
		int a, b; string S;
		scanf("%d", &a); cin >> S; scanf("%d", &b);
		if(S[0] == 'E') break;
		printf("Case %d: ", t);
		if(S == ">") cout << K[a>b] << endl;
		if(S == ">=") cout << K[a>=b] << endl;
		if(S == "<") cout << K[a<b] << endl;
		if(S == "<=") cout << K[a<=b] << endl;
		if(S == "==") cout << K[a==b] << endl;
		if(S == "!=") cout << K[a!=b] << endl;
	}
	return 0;
}











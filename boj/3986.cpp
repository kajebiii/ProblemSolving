// =====================================================================================
//
//       Filename:  3986.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/07/2016 10:29:24
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

char S[111111];
int main() {
	int T; scanf("%d\n", &T);
	int ans = 0;
	while(T--)
	{
		scanf("%s", S);
		stack<char> St;
		for(int i=0; S[i]; i++)
		{
			if(St.empty()) {St.push(S[i]); continue;}
			if(St.top() == S[i]) {St.pop(); continue;}
			St.push(S[i]);
		}
		if(St.empty()) ans++;
	}
	cout << ans;
	return 0;
}











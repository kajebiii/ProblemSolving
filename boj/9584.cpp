// =====================================================================================
//
//       Filename:  9584.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/26/2016 10:13:35
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

int main() {
	string S; cin >> S;
	vector<string> Ans;
	int N; cin >> N;
	while(N--)
	{
		string now; cin >> now;
		bool flag = true;
		for(int i=0; i<S.length(); i++)
			if(S[i] != '*' && now[i] != S[i])
				flag = false;
		if(flag) Ans.pb(now);
	}
	printf("%d", (int)Ans.size());
	for(string &now : Ans)
	{
		puts("");
		cout << now;
	}
	return 0;
}











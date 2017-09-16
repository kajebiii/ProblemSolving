// =====================================================================================
//
//       Filename:  1076.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 17:16:57
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

#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

int main() {
	map<string, pi> M;
	vector<string> V;
	V.push_back("black");
	V.push_back("brown");
	V.push_back("red");
	V.push_back("orange");
	V.push_back("yellow");
	V.push_back("green");
	V.push_back("blue");
	V.push_back("violet");
	V.push_back("grey");
	V.push_back("white");
	int p = 1, cnt = 0;
	for(string x : V)
		M[x] = mp(cnt++, p), p *= 10;

	long long Ans = 0;
	string A, B, C; cin >> A >> B >> C;
	Ans += M[B].fi;
	Ans += M[A].fi * 10;
	Ans *= 1ll * M[C].se;
	cout << Ans;
	return 0;
}











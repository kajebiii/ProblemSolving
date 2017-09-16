// =====================================================================================
//
//       Filename:  2754.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 00:45:31
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

using namespace std;

typedef pair<int, int> pi;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;

int main() {
	string K; cin >> K;
	map<char, int> M;
	for(char x='A'; x<='D'; x++) M[x] = ('D' - x + 1) * 10;
	M['F'] = 0; M['+'] = 3; M['0'] = 0; M['-'] = -3;
	int Ans = 0;
	for(char x : K) Ans += M[x];
	cout << Ans/10 << "." << Ans%10;
	return 0;
}











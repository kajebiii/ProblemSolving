// =====================================================================================
//
//       Filename:  1431.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 13:13:28
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

string S[1111];
int getSum(string &a)
{
	int r = 0;
	for(char x : a)
		if(x >= '0' && x <= '9')
			r += x - '0';
	return r;
}
bool cmp(string &a, string &b)
{
	if(a.length() != b.length())
		return a.length() < b.length();
	if(getSum(a) != getSum(b))
		return getSum(a) < getSum(b);
	return a < b;
}
int main() {
	int N; cin >> N;
	for(int i=0; i<N; i++) cin >> S[i];
	sort(S, S+N, cmp);
	for(int i=0; i<N; i++) 
	{
		cout << S[i]; puts("");
	}
	return 0;
}











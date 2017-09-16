// =====================================================================================
//
//       Filename:  1935.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/17/2016 13:05:59
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

double Nr[33];
int main() {
	int N; cin >> N;
	string S; cin >> S;
	for(int i=0; i<N; i++) scanf("%lf", &Nr[i]);

	stack<double> Op;
	for(char x : S)
	{
		if(x >= 'A' && x <= 'Z') {Op.push(Nr[x-'A']); continue;}
		double b = Op.top(); Op.pop();
		double a = Op.top(); Op.pop();
		if(x == '+') Op.push(a+b);
		if(x == '-') Op.push(a-b);
		if(x == '*') Op.push(a*b);
		if(x == '/') Op.push(a/b);
	}
	printf("%.2lf\n", Op.top());
	return 0;
}











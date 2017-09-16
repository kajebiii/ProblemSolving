// =====================================================================================
//
//       Filename:  2023.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/10/2016 21:58:11
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
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

bool isPrime(int n)
{
	if(n == 1) return false;
	for(int i=2; i*i<=n; i++)
		if(n % i == 0) return false;
	return true;
}
int main() {
	int N; cin >> N;
	vector<int> next;
	vector<int> now; now.pb(0);
	for(int n=1; n<=N; n++)
	{
		for(int x : now) for(int i=1; i<=9; i++)
			if(isPrime(x*10+i)) next.pb(x*10 + i);
		next.swap(now);
		next.clear();
	}
	for(int x : now) printf("%d\n", x);
	return 0;
}











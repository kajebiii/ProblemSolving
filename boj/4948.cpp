// =====================================================================================
//
//       Filename:  4948.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/13/2016 15:18:56
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

int Sum[123456*2 + 100];
bool notP[123456*2 + 100];
int main() {
	notP[1] = true;
	for(int i=2; i<=123456*2; i++) if(notP[i] == false)
		for(int j=i*2; j<=123456*2; j+=i) notP[j] = true;
	for(int i=1; i<=123456*2; i++) Sum[i] = Sum[i-1] + !notP[i];
	while(1)
	{
		int x; scanf("%d", &x);
		if(x == 0) break;
		printf("%d\n", Sum[2*x] - Sum[x]);
	}
	return 0;
}











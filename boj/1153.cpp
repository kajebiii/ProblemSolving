// =====================================================================================
//
//       Filename:  1153.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/13/2016 15:24:07
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

pi Pair[1000002];
vector<int> P;
bool notP[1000001];
int main() {
	int N; cin >> N;
	for(int i=2, j; i<=N; i++) if(notP[i] == false)
		for(j=i*2, P.pb(i); j<=N; j+=i) notP[j] = true;
	for(int i=4; i<=N; i+=2)
		for(int x : P) if(!notP[x] && !notP[i-x])
		{Pair[i] = mp(x, i-x); break;}
	if(N <= 7) printf("-1");
	else
	{
		if(N % 2 == 1) printf("2 3"), N -= 5;
		else printf("2 2"), N -= 4;
		printf(" %d %d\n", Pair[N].fi, Pair[N].se);
	}

	return 0;
}











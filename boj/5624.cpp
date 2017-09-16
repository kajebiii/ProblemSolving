// =====================================================================================
//
//       Filename:  5624.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/22/2016 15:56:43
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

int N, Nr[5555];
int T[422222];
int main() {
	int N; cin >> N;

	int ans = 0;
	for(int i=0; i<N; i++)
	{
		scanf("%d", &Nr[i]);
		bool find = false;
		for(int j=0; j<i; j++) if(T[Nr[i] - Nr[j] + 200000] == 1) find = true;
		for(int j=0; j<=i; j++) T[Nr[i] + Nr[j] + 200000] = 1;
		if(find) ans++;
	}
	cout << ans;
	return 0;
}











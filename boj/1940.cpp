// =====================================================================================
//
//       Filename:  1940.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 17:03:28
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

int N, M, Nr[22222];

int main() {
	cin >> N >> M; for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	sort(Nr, Nr+N);
	int l = 0, r = N-1, Ans = 0;
	while(l < r)
	{
		int now = Nr[l] + Nr[r];
		if(now == M) {Ans++, r--;}
		else if(now < M) l++; else r--;
	}
	cout << Ans;
	return 0;
}











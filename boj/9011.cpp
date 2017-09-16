// =====================================================================================
//
//       Filename:  9011.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 14:03:01
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

int N, Nr[111], Chk[111];
int main() {
	int T; cin >> T;
	while(T--)
	{
		scanf("%d", &N);
		for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
		for(int i=1; i<=N; i++) Chk[i] = 0;

		bool possible = true;
		for(int i=N-1; i>=0; i--)
		{
			int cnt = 0, j = 0;
			while(cnt < Nr[i]+1 && j+1 <= N) cnt += 1 - Chk[j+1], j++;
			if(cnt < Nr[i]+1) {possible = false; break;}
			Nr[i] = j; Chk[j] = 1;
		}
		if(!possible) puts("IMPOSSIBLE");
		else {for(int i=0; i<N; i++) printf("%d ", Nr[i]); puts("");}
	}
	return 0;
}











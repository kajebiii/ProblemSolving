// =====================================================================================
//
//       Filename:  5052.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/15/2016 16:39:18
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

ll Nr[11111];
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		int N; scanf("%d", &N);
		char A[11];
		set<ll> S;
		for(int i=0; i<N; i++)
		{
			scanf("%s", A);
			ll now = 0;
			for(int j=0; A[j]; j++)
				now *= 11, now += A[j] - '0' + 1;
			S.insert(now);
			Nr[i] = now;
		}
		
		bool isTrue = true;
		for(int i=0; i<N; i++)
		{
			while(Nr[i] /= 11)
				if(S.count(Nr[i]))
					isTrue = false;
			if(!isTrue) break;
		}
		if(isTrue) puts("YES");
		else puts("NO");
	}
	return 0;
}











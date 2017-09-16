// =====================================================================================
//
//       Filename:  5636.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/17/2016 14:38:27
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

bool notP[101101];
int main() {
	notP[1] = true;
	for(int i=2; i<=100000; i++)
		if(notP[i] == false)
			for(int j=i*2; j<=100000; j+=i)
				notP[j] = true;
	while(1)
	{
		string S; cin >> S; int N = S.length();
		if(S[0] == '0' && N == 1) break;
		int ans = 0;
		for(int i=0; i<N; i++)
		{
			int now = 0;
			if(S[i] == '0') continue;
			for(int j=0; j<5; j++)
			{
				if(i+j >= N) break;
				now *= 10; now += S[i+j] - '0';
				if(!notP[now]) ans = max(ans, now);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}











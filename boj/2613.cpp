// =====================================================================================
//
//       Filename:  2613.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/19/2016 11:56:52
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

int N, M, Nr[333];
int main() {
	cin >> N >> M; for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	int s = Nr[max_element(Nr, Nr+N) - Nr], e = INF/2;
	while(s < e)
	{
		int m = (s + e + 0) / 2;
		int cnt = 0, ix = 0;
		while(ix < N)
		{
			int now = 0;
			while(now + Nr[ix] <= m && ix < N) now += Nr[ix++];
			cnt++;
		}
		if(cnt <= M) e = m;
		else s = m + 1;
	}
	printf("%d\n", s);
	int ix = 0;
	while(ix < N)
	{
		int now = 0, cnt = 0;
		while(now + Nr[ix] <= s && ix < N-M+1) now += Nr[ix++], cnt++;
		printf("%d ", cnt);
		M--;
	}
	return 0;
}











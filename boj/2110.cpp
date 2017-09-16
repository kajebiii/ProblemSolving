// =====================================================================================
//
//       Filename:  2110.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 01:52:02
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
const int MAX_N = 2e5 + 200;

int N, C, Nr[MAX_N];

int main() {
	cin >> N >> C; for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	sort(Nr, Nr+N);
	int s = 0, e = 1000000000;
	int ans = -1;
	Nr[N] = INF;
	while(s <= e)
	{
		int m = (s + e) >> 1;
		int cnt = 0;
		int last = 0, i = 0;
		for(int c=1; c<C; c++)
		{
			while(Nr[i+1] - Nr[last] < m) i++;
			last = ++i;
			if(i == N) break;
		}
		if(i == N)
		{
			e = m - 1;
			continue;
		}
		s = m + 1;
		ans = max(ans, m);
	}
	cout << ans;
	return 0;
}











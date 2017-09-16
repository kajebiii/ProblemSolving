// =====================================================================================
//
//       Filename:  8979.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 22:57:20
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
#define fi first
#define se second

const int MAX_N = 1111;

int N, K;
pair<pi, pi> D[MAX_N];

int main() {
	cin >> N >> K;
	for(int i=1; i<=N; i++)
	{
		int g, s, b, p; scanf("%d%d%d%d", &p, &g, &s, &b);
		D[i] = mp(mp(g, s), mp(b, p));
	}
	sort(D + 1, D + N + 1);
	reverse(D + 1, D + N + 1);
	
	int last = -1;
	for(int i=1; i<=N; i++)
	{
		int now = -1;
		if(i == 1 || (D[i-1].fi.fi != D[i].fi.fi || D[i-1].fi.se != D[i].fi.se || D[i-1].se.fi != D[i].se.fi))
			now = i;
		else
			now = last;
		if(D[i].se.se == K)
		{
			printf("%d\n", now);
			break;
		}
		last = now;
	}
	return 0;
}











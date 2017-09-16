// =====================================================================================
//
//       Filename:  1966.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 17:28:06
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

using namespace std;

typedef pair<int, int> pi;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};

int main() {
	int T; cin >> T;
	while(T--)
	{
		int N, M;
		scanf("%d%d", &N, &M);
		deque<pi> Q;
		for(int i=0; i<N; i++)
		{
			int x; scanf("%d", &x);
			Q.push_back(mp(x, i));
		}
		int ans = 0;
		while(!Q.empty())
		{
			int nowMax = 0;
			for(pi x : Q)
				nowMax = max(nowMax, x.fi);
			pi now = Q.front(); Q.pop_front();
			if(now.fi != nowMax) 
			{
				Q.push_back(now);
				continue;
			}
			ans++;
			if(now.se == M)
			{
				printf("%d\n", ans);
				break;
			}
		}
	}
	return 0;
}











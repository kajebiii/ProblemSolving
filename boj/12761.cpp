// =====================================================================================
//
//       Filename:  12761.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 16:38:09
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

int Dis[101101];
int main() {
	int A, B, N, M; cin >> A >> B >> N >> M;
	for(int i=0; i<=100000; i++) Dis[i] = INF;
	queue<int> Q; Q.push(N); Dis[N] = 0;
	int ChP[8] = {1, -1, +A, -A, +B, -B, 0, 0};
	int ChM[8] = {1, 1, 1, 1, 1, 1, A, B};
	while(!Q.empty())
	{
		int now = Q.front(); Q.pop();
		if(now == M)
		{
			printf("%d", Dis[now]);
			break;
		}
		for(int k=0; k<8; k++)
		{
			int next = now * ChM[k] + ChP[k];
			if(next < 0 || next > 100000) continue;
			if(Dis[next] != INF) continue;
			Q.push(next);
			Dis[next] = Dis[now] + 1;
		}
	}
	return 0;
}











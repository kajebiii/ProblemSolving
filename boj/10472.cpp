// =====================================================================================
//
//       Filename:  10472.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 17:26:03
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
const pi Ch[5] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1), mp(0, 0)};

int Dis[1<<9];
char A[3][3]; 
int main() {
	for(int i=0; i<1<<9; i++) Dis[i] = INF;
	queue<int> Q; Q.push(0); Dis[0] = 0;
	while(!Q.empty())
	{
		int now = Q.front(); Q.pop();
		for(int i=0; i<3; i++) for(int j=0; j<3; j++)
		{
			int next = now;
			for(int k=0; k<5; k++)
			{
				int x = i+Ch[k].fi, y = j+Ch[k].se;
				if(x < 0 || y < 0 || x >= 3 || y >= 3) continue;
				next ^= (1<<(x*3+y));
			}
			if(Dis[next] == INF) {Dis[next] = Dis[now] + 1; Q.push(next);}
		}
	}

	int TC; cin >> TC;
	while(TC--)
	{
		int now = 0;
		for(int i=0; i<3; i++) scanf("%s", A[i]);
		for(int i=0; i<3; i++) for(int j=0; j<3; j++)
			if(A[i][j] == '*') now += 1<<(i*3+j);
		printf("%d\n", Dis[now]);
	}
	return 0;
}











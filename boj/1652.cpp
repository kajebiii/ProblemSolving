// =====================================================================================
//
//       Filename:  1652.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 21:02:21
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

int N, Cnt[111];
char Map[111][111];
int main() {
	cin >> N; for(int i=1; i<=N; i++) scanf("%s", Map[i]+1);
	for(int i=1; i<=N; i++) Map[N+1][i] = Map[i][N+1] = 'X';

	int ans[2] = {0, 0};
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N+1; j++)
			if(Map[i][j] == '.') Cnt[j] = Cnt[j-1] + 1;
			else 
			{
				if(Cnt[j-1] >= 2) ans[0]++;
				Cnt[j] = 0;
			}
		for(int j=1; j<=N+1; j++)
			if(Map[j][i] == '.') Cnt[j] = Cnt[j-1] + 1;
			else 
			{
				if(Cnt[j-1] >= 2) ans[1]++;
				Cnt[j] = 0;
			}
	}
	printf("%d %d", ans[0], ans[1]);
	return 0;
}












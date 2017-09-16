// =====================================================================================
//
//       Filename:  2250.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 12:31:42
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

int N, LR[11111][2];
int Lv[11111][2], cnt, InDeg[11111];
void go(int v, int l)
{
	if(v == -1) return;
	go(LR[v][0], l+1);
	++cnt;
	Lv[l][0] = min(Lv[l][0], cnt);
	Lv[l][1] = max(Lv[l][1], cnt);
	go(LR[v][1], l+1);
}
int main() {
	cin >> N;
	for(int i=0; i<N; i++)
	{
		int n, x, y; scanf("%d%d%d", &n, &x, &y);
		LR[n][0] = x; LR[n][1] = y;
		if(x != -1) InDeg[x]++; 
		if(y != -1) InDeg[y]++;
	}
	for(int i=1; i<=N; i++) Lv[i][0] = INF, Lv[i][1] = 0;
	int root = -1;
	for(int i=1; i<=N; i++) if(InDeg[i] == 0) root = i;
	go(root, 1);

	int maxV = -1, maxIx = -1;
	for(int i=1; i<=N; i++)
		if(maxV < Lv[i][1] - Lv[i][0])
		{
			maxV = Lv[i][1] - Lv[i][0];
			maxIx = i;
		}
	printf("%d %d\n", maxIx, maxV+1);
	return 0;
}











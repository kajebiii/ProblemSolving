// =====================================================================================
//
//       Filename:  1996.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/17/2016 21:59:52
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
const pi Ch[8] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1), mp(-1, -1), mp(1, 1), mp(-1, 1), mp(1, -1)};

int N; char Map[1111][1111];
int main() {
	cin >> N; for(int i=1; i<=N; i++) scanf("%s", Map[i] + 1);
	for(int i=1; i<=N; i++, puts("")) for(int j=1; j<=N; j++)
	{
		if(Map[i][j] != '.') {printf("*"); continue;}
		int cnt = 0;
		for(int k=0; k<8; k++)
		{
			int nx = i + Ch[k].fi, ny = j + Ch[k].se;
			if(Map[nx][ny] >= '1' && Map[nx][ny] <= '9')
				cnt += Map[nx][ny] - '0';
		}
		if(cnt >= 10) printf("M");
		else printf("%d", cnt);
	}
	return 0;
}











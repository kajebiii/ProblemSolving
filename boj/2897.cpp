// =====================================================================================
//
//       Filename:  2897.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 03:30:25
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

int R, C; char Nr[55][55];
int Ans[5];
int main() {
	cin >> R >> C; for(int i=0; i<R; i++) scanf("%s", Nr[i]);
	for(int i=0; i<R-1; i++) for(int j=0; j<C-1; j++)
	{
		int cnt = 0; bool flag = true;
		for(int k=0; k<4; k++)
		{
			int nx = i+k/2, ny = j+k%2;
			if(Nr[nx][ny] == '#') flag = false;
			if(Nr[nx][ny] == 'X') cnt++;
		}
		if(flag) Ans[cnt]++;
	}
	for(int i=0; i<5; i++) printf("%d\n", Ans[i]);
	return 0;
}











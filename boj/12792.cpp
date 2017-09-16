// =====================================================================================
//
//       Filename:  12792.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/10/2016 21:31:14
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
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int N, Nr[1001001], Visit[1001001];
int main() {
	cin >> N; for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	int cnt = 1;
	for(int i=1; i<=N; i++)
	{
		int now = i, start = cnt;
		while(Visit[now] == 0)
		{
			Visit[now] = cnt++;
			now = Nr[now];
		}
		if(Visit[now] >= start)
			if(Visit[now] == cnt - 1)
			{
				printf("-1");
				return 0;
			}
	}
	printf("1000003");
	return 0;
}











// =====================================================================================
//
//       Filename:  1058.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 20:14:40
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

int N, Chk[55]; char Map[55][55];
int main() {
	cin >> N; for(int i=1; i<=N; i++) scanf("%s", Map[i]+1);
	int ans = 0;
	for(int k=1; k<=N; k++)
	{
		for(int i=1; i<=N; i++) Chk[i] = INF;
		queue<int> Q; Q.push(k); Chk[k] = 0;
		int cnt = 0;
		while(!Q.empty())
		{
			int now = Q.front(); Q.pop(); cnt++;
			if(Chk[now] == 2) continue;
			for(int i=1; i<=N; i++)
				if(Map[now][i] == 'Y' && Chk[i] == INF)
				{
					Chk[i] = Chk[now] + 1;
					Q.push(i);
				}
		}
		ans = max(ans, cnt - 1);
	}
	cout << ans;
	return 0;
}











// =====================================================================================
//
//       Filename:  2252.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 13:18:13
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
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MAX_N = 33333;

int N, M;
vector<int> V[MAX_N];
int Cnt[MAX_N];

int main() {
	cin >> N >> M;
	for(int i=0; i<M; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		V[x].pb(y);
		Cnt[y]++;
	}
	queue<int> Q;
	for(int i=1; i<=N; i++) if(Cnt[i] == 0) Q.push(i);

	while(!Q.empty())
	{
		int now = Q.front(); Q.pop();
		printf("%d ", now);
		for(int x : V[now])
		{
			Cnt[x]--;
			if(Cnt[x] == 0) Q.push(x);
		}
	}
	return 0;
}










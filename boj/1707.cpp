// =====================================================================================
//
//       Filename:  1707.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 00:33:22
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
const int MAX_N = 2e4 + 200;

int N, M, Chk[MAX_N];
vector<int> V[MAX_N];

bool getOK(int v, int k)
{
	Chk[v] = k;
	for(int w : V[v])
	{
		if(Chk[w] == 0) if(!getOK(w, 3-k)) return false;
		if(Chk[w] && Chk[w] != 3-k) return false;
	}
	return true;
}

int main() {
	int T; cin >> T;
	while(T--)
	{
		scanf("%d%d", &N, &M);
		for(int i=0; i<M; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			V[x].pb(y); V[y].pb(x);
		}
		for(int i=1; i<=N; i++) Chk[i] = 0;

		bool isOK = true;
		for(int i=1; i<=N; i++)
			if(Chk[i] == 0 && !getOK(i, 1))
				isOK = false;
		if(isOK) puts("YES");
		else puts("NO");		

		for(int i=1; i<=N; i++)
		{
			V[i].clear();
			V[i].shrink_to_fit();
		}
	}
	return 0;
}











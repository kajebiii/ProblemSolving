// =====================================================================================
//
//       Filename:  9470.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/02/2016 21:50:44
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
const int MAX_N = 1111;

int N, M, Cnt[MAX_N], Str[MAX_N], MaxV[MAX_N], MaxC[MAX_N];
vector<int> V[MAX_N];

int main() {
	int T; cin >> T;
	while(T--)
	{
		int t; scanf("%d%d%d", &t, &N, &M);
		for(int i=0; i<M; i++) 
		{
			int x, y; scanf("%d%d", &x, &y);
			V[x].pb(y);
			Cnt[y]++;
		}
		queue<int> Q;
		for(int i=1; i<=N; i++) if(Cnt[i] == 0) Q.push(i), MaxV[i] = 0, MaxC[i] = 2;
		while(!Q.empty())
		{
			int i = Q.front(); Q.pop();
			Str[i] = MaxV[i];
			if(MaxC[i] >= 2) Str[i] = MaxV[i] + 1;
			for(int x : V[i])
			{
				if(MaxV[x] == Str[i]) MaxC[x]++;
				if(MaxV[x] < Str[i]) MaxC[x] = 1, MaxV[x] = Str[i];
				Cnt[x]--;
				if(Cnt[x] == 0) Q.push(x);
			}
		}

		printf("%d %d\n", t, Str[N]);

		for(int i=1; i<=N; i++)
		{
			Str[i] = 0;
			MaxV[i] = 0; MaxC[i] = 0;
			Cnt[i] = 0;
			V[i].clear();
			V[i].shrink_to_fit();
		}
	}
	return 0;
}











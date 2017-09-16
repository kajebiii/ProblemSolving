// =====================================================================================
//
//       Filename:  2570.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 20:10:39
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

int N, M, Nr[111][111];
int Cnt[2][111][111], CntN[2];
vector<int> V[111*111];
int Visit[111*111], Match[111*111];

bool findMatch(int v)
{
	if(Visit[v] == 1) return false;
	Visit[v] = 1;

	for(int w : V[v])
		if(Match[w] == 0 || findMatch(Match[w]))
		{
			Match[w] = v;
			return true;
		}
	return false;
}
int main() {
	cin >> N >> M; for(int x, y; M--; ) scanf("%d%d", &x, &y), Nr[x-1][y-1] = 1;
	for(int p=0; p<=2*N-2; p++)
	{
		bool start = false;
		for(int i=0; i<N; i++)
		{
			int j = p - i;
			if(j >= N) continue;
			if(Nr[i][j] == 0)
			{
				if(start == false) {start = true, CntN[0]++;}
				Cnt[0][i][j] = CntN[0];
			}else start = false;
		}
		start = false;
		for(int i=0; i<N; i++)
		{
			int j = p - (N-1) + i;
			if(j < 0 || j >= N) continue;
			if(Nr[i][j] == 0)
			{
				if(start == false) {start = true, CntN[1]++;}
				Cnt[1][i][j] = CntN[1];
			}else start = false;
		}
	}
	for(int i=0; i<N; i++) for(int j=0; j<N; j++)
		V[Cnt[0][i][j]].pb(Cnt[1][i][j]);

	int Ans = 0;
	for(int i=1; i<=CntN[0]; i++)
	{
		for(int j=1; j<=CntN[0]; j++) Visit[j] = 0;
		if(findMatch(i))
			Ans++;
	}
	cout << Ans;

	return 0;
}











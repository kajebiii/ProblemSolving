// =====================================================================================
//
//       Filename:  10218.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/26/2016 10:35:29
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
#include <assert.h>

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
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(0, 1), mp(1, 0)};

int N, M, Ex, Ey, Dy[2][22][22]; 
char Map[22][22], Ans[22], Cho[4] = {'U', 'L', 'R', 'D'};
map<char, int> Mp;
bool findAns = false;

char getMap(pi t) {return Map[t.fi][t.se];}
bool isAns(int L)
{
	int all = 0;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) 
		if(Map[i][j] == '.') Dy[1][i][j] = 1, all++; else Dy[1][i][j] = 0;
	for(int l=0; l<L; l++)
	{
		for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) Dy[l%2][i][j] = 0;
		int go = Mp[Ans[l]], other = 3 - go;
		for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
		{
			pi now = mp(i, j);
			if(getMap(now + Ch[go]) != '#' || getMap(now) != '.') continue;
			pi plus = now;
			while(getMap(plus) == '.')
			{
				Dy[l%2][now.fi][now.se] += Dy[1-l%2][plus.fi][plus.se];
				plus = plus + Ch[other];
			}
		}
		all -= Dy[l%2][Ex][Ey];
		Dy[l%2][Ex][Ey] = 0;
	}
	if(all == 0) return true;
	return false;
}
void findStr(int n, char p)
{
	if(n != 0 && isAns(n)) 
	{
		findAns = true;
		puts(Ans);
		return;
	}
	if(n >= 10) return;
	for(int k=0; k<4; k++)
	{
		if(Cho[k] == p) continue;
		Ans[n] = Cho[k];
		findStr(n+1, Cho[k]);
		if(findAns) return;
		Ans[n] = 0;
	}
}
int main() {
	int TC; cin >> TC;
	Mp['U'] = 0; Mp['L'] = 1; Mp['R'] = 2; Mp['D'] = 3;
	while(TC--)
	{
		scanf("%d%d", &N, &M);
		for(int i=1; i<=N; i++) scanf("%s", Map[i] + 1);
		for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) if(Map[i][j] == 'O')
			{Ex = i; Ey = j; Map[i][j] = '.';}
		for(int i=1; i<=N; i++) Map[i][0] = Map[i][M+1] = '#';
		for(int i=1; i<=M; i++) Map[0][i] = Map[N+1][i] = '#';
		findAns = false;
		findStr(0, 'X');
		if(findAns == false) puts("XHAE");
	}
	return 0;
}











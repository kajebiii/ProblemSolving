// =====================================================================================
//
//       Filename:  1197.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 18:53:47
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

using namespace std;

typedef pair<int, int> pi;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};
const int MAX_N = 1e4 + 100, MAX_M = 1e5 + 100;

struct LINE
{
	int x, y;
	int c;
	const bool operator<(const LINE &o) const
	{
		return c < o.c;
	}
};

int N, M;
LINE L[MAX_M];

int UNF[MAX_N];
int F(int v)
{
	return UNF[v] == 0 ? v : UNF[v] = F(UNF[v]);
}
void U(int a, int b)
{
	UNF[F(a)] = F(b);
}

int main() {
	cin >> N >> M;
	for(int i=0; i<M; i++) scanf("%d%d%d", &L[i].x, &L[i].y, &L[i].c);
	sort(L, L+M);
	
	long long ans = 0;
	for(int i=0; i<M; i++)
	{
		LINE &l = L[i];
		if(F(l.x) == F(l.y)) continue;
		U(l.x, l.y);
		ans += 1ll * l.c;
	}
	cout << ans;
	return 0;
}











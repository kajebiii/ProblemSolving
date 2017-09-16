// =====================================================================================
//
//       Filename:  1922.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 14:41:32
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

struct LINE
{
	int x, y;
	int c;
	const bool operator<(const LINE &other) const
	{
		return c < other.c;
	}
};

int N, M;
LINE L[111111];

int UNF[1111];
int F(int v)
{
	return UNF[v]==0?v:UNF[v]=F(UNF[v]);
}
void U(int a, int b)
{
	a = F(a), b = F(b);
	if(a == b) return;
	UNF[b] = a;
}

int main() {
	cin >> N >> M;
	for(int i=0; i<M; i++)
		scanf("%d%d%d", &L[i].x, &L[i].y, &L[i].c);
	sort(L, L+M);
	
	int ans = 0;
	for(int i=0; i<M; i++)
	{
		int a = L[i].x, b = L[i].y;
		if(F(a) != F(b))
		{
			U(a, b);
			ans += L[i].c;
		}
	}
	cout << ans;
	return 0;
}











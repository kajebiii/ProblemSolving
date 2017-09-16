// =====================================================================================
//
//       Filename:  1507.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/18/2016 03:05:30
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

int N, Nr[33][33], LN, Now[33][33];
struct LINE{int x, y, c;}L[33*33];
bool cmp(const LINE &A, const LINE &B) {return A.c < B.c;}
int main() {
	cin >> N; for(int i=0; i<N; i++) for(int j=0; j<N; j++)
	{
		scanf("%d", &Nr[i][j]);
		if(i <= j) L[LN++] = (LINE){i, j, Nr[i][j]};
	}
	sort(L, L+LN, cmp);
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) Now[i][j] = INF;
	
	int sum = 0;
	for(int l=0; l<LN; l++)
	{
		int x = L[l].x, y = L[l].y, c = L[l].c;
		if(Now[x][y] > c)
		{
			Now[x][y] = Now[y][x] = c;
			for(int i=0; i<N; i++) for(int j=0; j<N; j++)
				if(Now[i][x] != INF && Now[y][j] != INF)
					Now[i][j] = min(Now[i][j], Now[i][x] + Now[y][j] + Now[x][y]);
			swap(x,y);
			for(int i=0; i<N; i++) for(int j=0; j<N; j++)
				if(Now[i][x] != INF && Now[y][j] != INF)
					Now[i][j] = min(Now[i][j], Now[i][x] + Now[y][j] + Now[x][y]);
			sum += c;
		}
		else if(Now[x][y] < c)
		{
			puts("-1");
			return 0;
		}
	}
	cout << sum;
	return 0;
}











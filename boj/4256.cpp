// =====================================================================================
//
//       Filename:  4256.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/04/2016 16:07:49
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

int A[MAX_N], B[MAX_N], N;
void printAns(int ax, int ay, int bx, int by)
{
	if(bx > by) return;
	int bm = -1; for(int i=bx; i<=by; i++) if(B[i] == A[ax]) bm = i;
	printAns(ax+1, ax+bm-bx, bx, bm-1);
	printAns(ax+bm-bx+1, ay, bm+1, by);
	printf("%d ", A[ax]);
}
int main() {
	int T; cin >> T;
	while(T--)
	{
		scanf("%d", &N);
		for(int i=1; i<=N; i++) scanf("%d", &A[i]);
		for(int i=1; i<=N; i++) scanf("%d", &B[i]);
		printAns(1, N, 1, N); printf("\n");
	}
	return 0;
}











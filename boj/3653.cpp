// =====================================================================================
//
//       Filename:  3653.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  10/04/2016 16:40:42
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
const pi Ch[8] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1), mp(-1, -1), mp(-1, 1), mp(1, -1), mp(1, 1)};
const int MAX_N = 1e5 + 100;

int N, M, P, T[MAX_N*2*4], Idx[MAX_N];
void update(int v, int k) {T[v] = k; while(v/=2) T[v] = T[v*2] + T[v*2+1];}
int get(int a, int b) {return a>b?0:get((a+1)/2, (b-1)/2)+(a%2==1?T[a]:0)+(b%2==0?T[b]:0);}
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		scanf("%d%d", &N, &M);
		for(P=1; P<N+M; P<<=1);
		for(int i=1; i<2*P; i++) T[i] = 0;
		for(int i=0; i<N; i++) update(P+i, 1);
		for(int i=0; i<N; i++) Idx[i] = N-1-i;
		for(int i=0; i<M; i++)
		{
			int x; scanf("%d", &x); x--;
			printf("%d ", get(P+Idx[x]+1, P+N+M-1));
			update(P+Idx[x], 0);
			Idx[x] = N+i;
			update(P+Idx[x], 1);
		}
		puts("");
	}
	return 0;
}











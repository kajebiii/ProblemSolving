// =====================================================================================
//
//       Filename:  10800.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/23/2016 13:21:20
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
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MAX_N = 2e5 + 200, MAX_S = 2e3 + 100;

struct NODE
{
	int c, s, ix;
	NODE() {c = s = ix = -1;}
	NODE(int _c, int _s, int _ix) {c = _c, s = _s, ix = _ix;}
	const bool operator<(const NODE &o) const{return s < o.s;}
}Ball[MAX_N];
int Ans[MAX_N], Sum[MAX_N], SumV, N;
int main() {
	cin >> N;
	for(int i=0; i<N; i++)
	{
		scanf("%d%d", &Ball[i].c, &Ball[i].s);
		Ball[i].ix = i;
	}
	sort(Ball, Ball + N);
	for(int l=0; l<N; )
	{
		int r = l;
		while(r < N && Ball[r].s == Ball[l].s) r++;
		for(int i=l; i<r; i++)
			Ans[Ball[i].ix] = SumV - Sum[Ball[i].c];
		for(int i=l; i<r; i++)
		{
			Sum[Ball[i].c] += Ball[i].s;
			SumV += Ball[i].s;
		}
		l = r;
	}
	for(int i=0; i<N; i++) printf("%d\n", Ans[i]);
	return 0;
}











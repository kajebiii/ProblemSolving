// =====================================================================================
//
//       Filename:  10165.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/17/2016 13:48:17
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
const int MAX_N = 5e5 + 100;

struct LINE{int x, y, ix;}Nr[MAX_N * 2];
bool cmp(const LINE &a, const LINE &b){return a.x==b.x?a.y>b.y:a.x<b.x;}
int L, nN, N; bool Chk[MAX_N];
int main() {
	cin >> L >> nN; N = nN;
	for(int i=0; i<nN; i++)
	{
		scanf("%d%d", &Nr[i].x, &Nr[i].y); Nr[i].ix = i;
		if(Nr[i].x > Nr[i].y) Nr[i].y += L;
		else Nr[N++] = {Nr[i].x + L, Nr[i].y + L, Nr[i].ix};
	}
	sort(Nr, Nr+N, cmp);
	int r = -1;
	for(int i=0; i<N; i++)
		if(Nr[i].y <= r)
			Chk[Nr[i].ix] = true;
		else r = Nr[i].y;
	for(int i=0; i<nN; i++)
		if(!Chk[i]) printf("%d ", i+1);
	return 0;
}











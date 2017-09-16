// =====================================================================================
//
//       Filename:  7149.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/04/2016 14:25:55
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
const int MAX_N = 1e5 + 100;

int N, P, T[MAX_N*4], Cnt[MAX_N], Sx[MAX_N], Idx[MAX_N][2];
struct DATA{int x, r, ix;}D[MAX_N];
bool cmpX(const DATA &a, const DATA &b) {return a.x < b.x;}
bool cmpRX(const DATA &a, const DATA &b) {return a.x-a.r<b.x-b.r || (a.x-a.r==b.x-b.r && a.x>b.x);}
void update(int v, int k) {T[v]=k; while(v/=2) {T[v] = min(T[v*2], T[v*2+1]);}}
int get(int a, int b)
{
	int r = INF;
	while(a<=b)
	{
		if(  a%2) r = min(r, T[a++]);
		if(1-b%2) r = min(r, T[b--]);
		a /= 2; b /= 2;
	}
	return r;
}

void plusCnt()
{
	sort(D, D+N, cmpX);
	for(int i=0; i<N; i++) Sx[i] = D[i].x;
	for(int i=0; i<N; i++)
	{
		Idx[i][0] = (int)(lower_bound(Sx, Sx+N, D[i].x-D[i].r) - Sx);
		Idx[i][1] = (int)(upper_bound(Sx, Sx+N, D[i].x+D[i].r) - Sx - 1);
	}
	for(int i=1; i<2*P; i++) T[i] = INF;
	
	
	for(int k=0; k<32; k++)
	{
		int i = k%2 ? N-1 : 0, p = k%2 ? -1 : 1;
		while(i>=0 && i<N)
		{
			int &l = Idx[i][0], &r = Idx[i][1];
			int val = min(l, get(P+l, P+r));
			update(P+i, val);
			i += p;
		}
	}
	for(int i=0; i<N; i++)
	{
		int val = T[P+i];
		Cnt[D[i].ix] += abs(val - i);
	}
}

int main() {
	while(1)
	{
		scanf("%d", &N); if(N == 0) break; for(P=1; P<N; P<<=1);
		for(int i=0; i<N; i++) scanf("%d%d", &D[i].x, &D[i].r), D[i].ix = i;
		plusCnt();
		for(int i=0; i<N; i++) D[i].x *= -1;
		plusCnt();
		for(int i=0; i<N; i++) printf("%d ", Cnt[i]+1); printf("\n");
		for(int i=0; i<N; i++) Cnt[i] = 0;
	}
	return 0;
}











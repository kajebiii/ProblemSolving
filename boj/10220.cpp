// =====================================================================================
//
//       Filename:  10220.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 21:28:35
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

int N, A[111], Cnt[111], Ans;
void find(int n, int sum, int multi)
{
	if(sum > N || multi > N) return;
	if(n == N)
	{
		for(int i=0; i<N; i++) Cnt[i] = 0;
		for(int i=0; i<N; i++) Cnt[A[i]]++;
		bool flag = true;
		for(int i=0; i<N; i++) if(Cnt[i] != A[i]) flag = false;
		if(flag) 
			Ans++;
		return;
	}
	for(int i=0; i<N; i++)
	{
		A[n] = i;
		find(n+1, sum+i, multi + i*n);
	}
}
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		scanf("%d", &N);
		if(N == 4) puts("2");
		else if(N <= 3 || N == 6) puts("0");
		else puts("1");
	}
	return 0;
}











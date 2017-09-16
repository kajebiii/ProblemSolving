// =====================================================================================
//
//       Filename:  11582.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/23/2016 14:11:47
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

int N, Nr[1<<21], O[1<<21], P;
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	cin >> P; P = N / P;
	for(int p=2; p<=P; p<<=1)
	{
		for(int i=0; i<N; i++) O[i] = Nr[i];
		for(int i=0; i<N; i+=p)
		{
			int l = i, r = i + p/2, cnt = i;
			while(cnt < i+p)
				if(l == (i+p/2) || (r != (i+p) && O[l] >= O[r]))
					Nr[cnt++] = O[r++];
				else
					Nr[cnt++] = O[l++];
		}
	}
	for(int i=0; i<N; i++) printf("%d ", Nr[i]);
	return 0;
}











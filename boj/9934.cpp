// =====================================================================================
//
//       Filename:  9934.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/11/2016 00:06:20
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
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int Cnt = 0, K;
int Nr[1<<10], Ans[1<<10];
void fillAns(int v)
{
	if(v >= (1<<K)) return;
	fillAns(v*2);
	Ans[v] = Nr[Cnt++];
	fillAns(v*2+1);
}
int main() {
	cin >> K; for(int i=0; i<(1<<K)-1; i++) scanf("%d", &Nr[i]);
	fillAns(1);
	int l = 1, r = 1;
	for(int k=0; k<K; k++, puts(""))
	{
		for(int i=l; i<=r; i++) printf("%d ", Ans[i]);
		l = l * 2;
		r = r * 2 + 1;
	}
	return 0;
}











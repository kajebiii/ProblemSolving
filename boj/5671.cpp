// =====================================================================================
//
//       Filename:  5671.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 14:37:47
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

int Sum[5555], Chk[10];
bool isGood(int v)
{
	for(int i=0; i<10; i++) Chk[i] = 0;
	Chk[v%10]++;
	while(v/=10) if(++Chk[v%10] > 1) return false;
	return true;
}
int main() {
	for(int i=1; i<=5000; i++)
		Sum[i] = Sum[i-1] + isGood(i);
	int N, M;
	while(scanf("%d%d", &N, &M) != EOF) printf("%d\n", Sum[M] - Sum[N-1]);
	return 0;
}











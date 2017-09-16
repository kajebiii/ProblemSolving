// =====================================================================================
//
//       Filename:  3020.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 18:03:03
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
const int MAX_N = 2e5 + 200, MAX_H = 5e5 + 500;

int N, H, Cnt[2][MAX_H], CntAll[MAX_H];
int minVal = INF, minCnt;

int main() {
	cin >> N >> H;
	for(int x, i=0; i<N; i++) 
	{
		scanf("%d", &x);
		if(i%2) Cnt[1][H-x+1]++;
		else Cnt[0][x]++;
	}
	for(int sum = 0, i=H; i>=1; i--) sum += Cnt[0][i], CntAll[i] += sum;
	for(int sum = 0, i=1; i<=H; i++) sum += Cnt[1][i], CntAll[i] += sum;
	for(int i=1; i<=H; i++)
	{
		if(CntAll[i] == minVal) minCnt++;
		if(CntAll[i] <  minVal) minVal = CntAll[i], minCnt = 1;
	}
	printf("%d %d", minVal, minCnt);
	return 0;
}











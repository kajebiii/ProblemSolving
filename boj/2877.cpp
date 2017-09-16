// =====================================================================================
//
//       Filename:  2877.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/18/2016 14:16:01
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

void printAns(int k, int cnt)
{
	if(cnt == 0) return;
	printAns(k/2, cnt-1);
	if(k%2) printf("7");
	else printf("4");
}
int main() {
	int K; cin >> K; K--;
	int power = 2, cnt = 1;
	while(K >= power)
	{
		K -= power;
		power *= 2;
		cnt++;
	}
	printAns(K, cnt);
	return 0;
}











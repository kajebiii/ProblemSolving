// =====================================================================================
//
//       Filename:  1668.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/15/2016 08:40:16
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

int N, Nr[55];
int printAns()
{
	int now = 0, cnt = 0;
	for(int i=0; i<N; i++)
		if(now < Nr[i])
			now = Nr[i], cnt++;
	return cnt;
}
int main() {
	cin >> N; for(int i=0; i<N; i++) cin >> Nr[i];
	int l = printAns();
	reverse(Nr, Nr+N);
	int r = printAns();
	printf("%d\n%d", l, r);
	return 0;
}











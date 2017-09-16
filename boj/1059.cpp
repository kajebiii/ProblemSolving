// =====================================================================================
//
//       Filename:  1059.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/23/2016 09:20:21
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

int N, Nr[55];
int main() {
	cin >> N; N++; 
	Nr[0] = 0;
	for(int i=1; i<N; i++) scanf("%d", &Nr[i]);
	sort(Nr, Nr+N);
	int K; scanf("%d", &K);
	int ix = (int)(lower_bound(Nr, Nr+N, K) - Nr);
	if(Nr[ix] == K) puts("0");
	else
	{
		int l = K - Nr[ix-1], r = Nr[ix] - K;
		printf("%d\n", l * r - 1);
	}

	return 0;
}











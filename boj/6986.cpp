// =====================================================================================
//
//       Filename:  6986.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 17:51:29
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

int N, K;
int Nr[101101];
int main() {
	cin >> N >> K; 
	for(int i=0, x, y; i<N; i++) scanf("%d.%d", &x, &y), Nr[i] = x*10+y;
	sort(Nr, Nr+N);
	int sum = 0; for(int i=K; i<N-K; i++) sum += Nr[i];
	printf("%.2lf\n%.2lf", 1.0 * sum / 10 / (N-2*K) + 1e-6
						   , 1.0 * (sum + Nr[K]*K + Nr[N-K-1]*K) / 10 / N + 1e-6);
	return 0;
}











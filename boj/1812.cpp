// =====================================================================================
//
//       Filename:  1812.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 18:45:52
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

int N, Nr[1111], sum;
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%d", &Nr[i]), sum += Nr[i];
	sum /= 2; for(int i=1; i<N; i+=2) sum -= Nr[i];
	printf("%d", sum);
	for(int i=0; i<N-1; i++)
		printf("\n%d", sum = Nr[i] - sum);
	return 0;
}










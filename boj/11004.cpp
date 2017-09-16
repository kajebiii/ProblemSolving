// =====================================================================================
//
//       Filename:  11004.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 18:19:03
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

int N, K, Nr[5005005];
int main() {
	cin >> N >> K; for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	nth_element(Nr, Nr+K-1, Nr+N); cout << Nr[K-1];
	return 0;
}











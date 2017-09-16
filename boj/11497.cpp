// =====================================================================================
//
//       Filename:  11497.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 19:41:40
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

int N, Nr[11111];
int main() {
	int T; cin >> T;
	while(T--)
	{
		int Ans = 0;
		scanf("%d", &N); for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
		sort(Nr, Nr+N);
		for(int i=2; i<N; i++) Ans = max(Ans, Nr[i] - Nr[i-2]);
		printf("%d\n", Ans);
	}
	return 0;
}











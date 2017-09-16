// =====================================================================================
//
//       Filename:  11637.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/10/2016 23:31:29
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

int N, Nr[22];
int main() {
	int T; cin >> T;
	while(T--)
	{
		scanf("%d", &N); for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
		int sum = accumulate(Nr, Nr+N, 0);
		int maxix = max_element(Nr, Nr+N) - Nr;
		int maxV = Nr[maxix];
		int cnt = 0;
		for(int i=0; i<N; i++) if(Nr[i] == maxV) cnt++;
		if(cnt > 1) puts("no winner");
		else
			if(maxV * 2 > sum) printf("majority winner %d\n", maxix + 1);
			else printf("minority winner %d\n", maxix + 1);
	}
	return 0;
}











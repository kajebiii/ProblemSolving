// =====================================================================================
//
//       Filename:  1931.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 19:20:13
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
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};
const int MAX_N = 1e5 + 100;

int N;
pi Nr[MAX_N];

int main() {
	cin >> N;
	for(int i=0; i<N; i++) scanf("%d%d", &Nr[i].se, &Nr[i].fi);
	sort(Nr, Nr+N);
	int now = -INF, cnt = 0;;
	for(int i=0; i<N; i++)
		if(now <= Nr[i].se)
			cnt++, now = Nr[i].fi;
	cout << cnt;
	return 0;
}











// =====================================================================================
//
//       Filename:  1783.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/02/2016 22:24:33
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

int main() {
	int N, M; cin >> N >> M;
	if(N == 1) {printf("1"); return 0;}
	if(N == 2) {printf("%d", min(4, (M+1)/2)); return 0;}
	if(N >= 3)
	{
		if(M <= 4) {printf("%d", M); return 0;}
		if(M >= 7) {printf("%d", M-2); return 0;}
		printf("4");
	}
	return 0;
}










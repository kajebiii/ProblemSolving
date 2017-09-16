// =====================================================================================
//
//       Filename:  1267.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 18:27:27
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
	int N, sumY = 0, sumM = 0; cin >> N;
	for(int x, i=0; i<N; i++) cin >> x, sumY += x/30*10+10, sumM += x/60*15+15;
	if(sumY < sumM)
		printf("Y %d\n", sumY);
	else if(sumM < sumY)
		printf("M %d\n", sumM);
	else
		printf("Y M %d\n", sumM);
	return 0;
}










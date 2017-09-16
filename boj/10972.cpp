// =====================================================================================
//
//       Filename:  10972.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/05/2016 10:30:52
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

int Nr[11111], N;
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	if(next_permutation(Nr, Nr+N) == false) printf("-1");
	else for(int i=0; i<N; i++) printf("%d ", Nr[i]);
	return 0;
}










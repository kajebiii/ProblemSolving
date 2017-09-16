// =====================================================================================
//
//       Filename:  10834.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 14:34:06
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

int gcd(int a, int b) {return b?gcd(b, a%b):a;}
int main() {
	int N; cin >> N;
	int ansc = 0, ansr = 1;
	for(int i=0; i<N; i++)
	{
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		if(c == 1) ansc = 1 - ansc;
		int g = gcd(a, b); a /= g; b /= g;
		ansr *= b;
		ansr /= a;
	}
	printf("%d %d", ansc, ansr);
	return 0;
}











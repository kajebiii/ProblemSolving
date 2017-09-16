// =====================================================================================
//
//       Filename:  3036.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 01:10:42
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

int gcd(int a, int b) {return a?gcd(b%a, a):b;}
int main() {
	int N; cin >> N; int A; cin >> A;
	for(int i=1; i<N; i++)
	{
		int B; scanf("%d", &B);
		int G = gcd(A, B);
		printf("%d/%d\n", A/G, B/G);
	}
	return 0;
}










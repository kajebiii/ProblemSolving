// =====================================================================================
//
//       Filename:  10253.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 15:47:36
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
	int T; cin >> T;
	while(T--)
	{
		int A, B; scanf("%d%d", &A, &B);
		while(A != 1)
		{
			int x = B/A + 1;
			A *= x; A -= B; B *= x;
			int g = gcd(A, B);
			A /= g; B /= g;
		}
		printf("%d\n", B);
	}
	return 0;
}











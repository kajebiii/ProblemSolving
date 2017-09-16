// =====================================================================================
//
//       Filename:  1145.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 15:15:11
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
int lcm(int a, int b) {return a*b/gcd(a,b);}
int main() {
	int A[5]; for(int i=0; i<5; i++) cin >> A[i];

	int ans = INF;
	for(int i=0; i<5; i++) for(int j=i+1; j<5; j++) for(int k=j+1; k<5; k++)
		ans = min(ans, lcm(A[i], lcm(A[j], A[k])));
	cout << ans;
	return 0;
}











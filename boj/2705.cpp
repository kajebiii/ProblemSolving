// =====================================================================================
//
//       Filename:  2705.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/02/2016 22:33:38
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

ll Dy[1111];
int main() {
	Dy[0] = 1;
	for(int i=1; i<=1000; i++)
		for(int j=i%2; j<=i; j+=2)
			Dy[i] += Dy[(i-j)/2];

	int T; cin >> T;
	while(T--)
	{
		int N; scanf("%d", &N);
		printf("%lld\n", Dy[N]);
	}
	return 0;
}











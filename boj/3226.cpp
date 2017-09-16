// =====================================================================================
//
//       Filename:  3226.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 21:35:13
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
	int T; cin >> T;

	int Ans = 0;
	while(T--)
	{
		int A, B, C; scanf("%02d:%02d %02d", &A, &B, &C);
		int D = A*60 + B, E = A*60 + B + C;
		int S[10] = {0, 7*60, 19*60, 100*60};
		int SS[3] = {5, 10, 5};

		int now = 0;
		for(int i=0; i<3; i++)
		{
			if(E <= S[i] || S[i+1] <= D) continue;
			int a = max(S[i], D), b = min(S[i+1], E);
			now += SS[i] * (b-a);
		}
		Ans += now;
	}
	cout << Ans;
	return 0;
}











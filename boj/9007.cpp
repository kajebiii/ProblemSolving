// =====================================================================================
//
//       Filename:  9007.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  10/04/2016 12:34:31
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
#include <assert.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int Nr[4][1111];
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		int K, N; cin >> K >> N;
		for(int j=0; j<4; j++) for(int i=0; i<N; i++)
			scanf("%d", &Nr[j][i]);
		vector<int> A, B;
		for(int i=0; i<N; i++) for(int j=0; j<N; j++)
			A.pb(Nr[0][i] + Nr[1][j]), B.pb(Nr[2][i] + Nr[3][j]);
		sort(B.begin(), B.end());
		
		int ans = -INF / 2;
		for(int x : A)
		{
			int ix[2];
			ix[1] = (int)(lower_bound(B.begin(), B.end(), K - x) - B.begin());
			ix[0] = ix[1] - 1;
			for(int k=0; k<2; k++)
			{
				int now = ix[k];
				if(now < 0 || now >= (int)B.size()) continue;
				if(abs(K - ans) > abs(K - B[now] - x) || (abs(K - ans) == abs(K - B[now] - x) && ans > B[now] + x))
					ans = B[now] + x;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}











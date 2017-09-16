// =====================================================================================
//
//       Filename:  7573.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/20/2016 12:46:14
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

int L, K, N, Nr[111][2];
int main() {
	cin >> L >> K >> N; K /= 2;
	for(int i=0; i<N; i++) for(int j=0; j<2; j++) scanf("%d", &Nr[i][j]);
	
	int ans = 0;
	for(int k=0; k<N; k++)
	{
		for(int r=1; r<K; r++)
		{
			int c = K - r;
			for(int l=0; l<=r; l++)
			{
				// Nr[k][0] - (r-l) to Nr[k][0] + l;
				int cnt = 0;
				for(int i=0; i<N; i++)
				{
					int dx = Nr[i][0] - (Nr[k][0] - (r-l));
					int dy = Nr[i][1] - Nr[k][1];
					if(dx <= r && dx >= 0 && dy <= c && dy >= 0) cnt++;
				}
				ans = max(ans, cnt);
			}
		}
	}
	cout << ans;
	return 0;
}











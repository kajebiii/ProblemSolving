// =====================================================================================
//
//       Filename:  9537.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/24/2016 22:57:44
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

using namespace std;

typedef pair<long long, int> pi;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};
const int MAX_N = 1e5 + 100;

int N;
vector<pi> V[2];

long long gcd(long long a, long long b)
{
	return a == 0 ? b : gcd(b%a, a);
}

int main() {
	int T; cin >> T;
	for(; T--;)
	{
		scanf("%d", &N);

		long long ans = 0;
		for(int i=0; i<2; i++)
			V[i].clear();
		for(int i=0; i<N; i++)
		{
			long long x; scanf("%lld", &x);
			V[1-i%2].clear();

			V[i%2].push_back(mp(0, i));
			int cnt = 0;
			for(pi &v : V[i%2])
			{
				v.fi = gcd(v.fi, x);
				ans = max(ans, v.fi * (i - v.se + 1));
				if(cnt == 0 || (cnt > 0 && V[i%2][cnt].fi != V[i%2][cnt-1].fi) )
					V[1-i%2].push_back(v);
				cnt++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}











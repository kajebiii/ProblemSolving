// =====================================================================================
//
//       Filename:  2912.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 15:31:18
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

typedef pair<int, int> pi;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int MAX_N = 3e5 + 300;

int N, C, P;
vector<int> V[MAX_N*4];

pi get(int a, int b, int k)
{
	pi result = mp(0, 0);
	while(a <= b)
	{
		if(  a%2)
		{
			int low = (int)(lower_bound(V[a].begin(), V[a].end(), k) - V[a].begin());
			int upp = (int)(upper_bound(V[a].begin(), V[a].end(), k) - V[a].begin());
			result.fi += upp;
			result.se += (upp - low); a++;
		}
		if(1-b%2)
		{
			int low = (int)(lower_bound(V[b].begin(), V[b].end(), k) - V[b].begin());
			int upp = (int)(upper_bound(V[b].begin(), V[b].end(), k) - V[b].begin());
			result.fi += upp;
			result.se += (upp - low); b--;
		}
		a /= 2; b /= 2;
	}
	return result;
}

int main() {
	scanf("%d%d", &N, &C);
	for(P=1; P<N; P<<=1);
	for(int x, i=0; i<N; i++)
		scanf("%d", &x), V[P+i].push_back(x);
	for(int i=P-1; i>=1; i--)
	{
		vector<int> A = V[i*2], B = V[i*2+1];
		int AN = (int)A.size(), BN = (int)B.size();
		int a = 0, b = 0;
		while(a < AN || b < BN)
			if(b == BN || (a < AN && b < BN && A[a] <= B[b]) )
				V[i].push_back(A[a++]);
			else
				V[i].push_back(B[b++]);
	}

	int M; scanf("%d", &M);
	for(; M--; )
	{
		int x, y; scanf("%d%d", &x, &y);
		int s = 1, e = C, m;
		int ans = -1;

		while(s <= e)
		{
			int m = (s + e) / 2;
			pi data = get(P + x - 1, P + y - 1, m);
			if(data.fi > (y-x+1) / 2)
			{
				e = m - 1;
				if(data.se > (y-x+1) / 2)
					ans = m;
			}
			else
				s = m + 1;
		}
		if(ans == -1)
			printf("no\n");
		else
			printf("yes %d\n", ans);
	}
	return 0;
}











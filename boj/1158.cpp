// =====================================================================================
//
//       Filename:  1168.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 01:26:46
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
const int MAX_N = 1e5 + 100;

int N, K, P, T[MAX_N*6];

void U(int v, int k)
{
	T[v] = k; while(v/=2) T[v] = T[v*2] + T[v*2+1];
}
int G(int a, int b)
{
	int r = 0;
	while(a<=b)
	{
		if(a%2) r+=T[a++];
		if(1-b%2) r+=T[b--];
		a/=2; b/=2;
	}
	return r;
}

int main() {
	cin >> N >> K;
	for(P=1; P<2*N; P<<=1);
	printf("<%d", K);
	for(int i=0; i<2*N; i++)
		if(i%N != K-1)
			U(P+i, 1);
	int now = K-1;

	for(int i=N-1; i>=1; i--)
	{
		int find = (K-1)%i + 1;
		int r = 1, f = N, m;
		int index = -1;
		while(r <= f)
		{
			int m = (r + f) / 2;
			int sum = G(P+now+1, P+now+m);
			if(sum >= find)
			{
				if(sum == find) index = m;
				f = m - 1;
			}
			else
				r = m + 1;
		}
		U(P+(now+index)%N, 0);
		U(P+(now+index)%N+N, 0);
		printf(", %d", (now+index)%N+1);
		now = (now+index)%N;
	}
	printf(">\n");
	return 0;
}











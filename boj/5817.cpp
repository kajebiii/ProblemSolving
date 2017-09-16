// =====================================================================================
//
//       Filename:  5817.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 17:02:30
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
const int MAX_N = 2e5 + 200;

int N, M, T[MAX_N * 4][2], P;
int Where[MAX_N];

void Update(int i, int k)
{
	Where[k] = i - P;
	T[i][0] = T[i][1] = k;
	while(i /= 2)
		T[i][0] = max(T[i*2][0], T[i*2+1][0]), T[i][1] = min(T[i*2][1], T[i*2+1][1]);
}
pi Get(int a, int b)
{
	pi result = mp(0, INF);
	while(a <= b)
	{
		if(  a%2)
		{
			result.fi = max(result.fi, T[a][0]);
			result.se = min(result.se, T[a++][1]);
		}
		if(1-b%2)
		{
			result.fi = max(result.fi, T[b][0]);
			result.se = min(result.se, T[b--][1]);
		}
		a /= 2; b /= 2;
	}
	return result;
}

int main() {
	cin >> N >> M;
	for(P=1; P<N; P<<=1);
	for(int i=0; i<N; i++) scanf("%d", &T[P+i][0]), T[P+i][1] = T[P+i][0];
	for(int i=P+N; i<2*P; i++) T[i][1] = INF;
	for(int i=P-1; i>=1; i--)
		T[i][0] = max(T[i*2][0], T[i*2+1][0]), T[i][1] = min(T[i*2][1], T[i*2+1][1]);
	for(int i=0; i<N; i++)
		Where[T[P+i][0]] = i;
	for(; M--; )
	{
		int type; scanf("%d", &type);
		int x, y; scanf("%d%d", &x, &y);
		if(type == 1)
		{
			int temp = T[P+x-1][0];
			Update(P+x-1, T[P+y-1][0]);
			Update(P+y-1, temp);
		}
		if(type == 2)
		{
			int a = Where[x], b = Where[y];
			if(a > b) swap(a, b);
			pi get = Get(P + a, P + b);
			if(get.fi != y || get.se != x)
				printf("NO\n");
			else
			{
				int r = 0, f = N, m, left = -1, right = -1;
				while(r <= f)
				{
					m = (r + f) / 2;
					if(a - m < 0)
					{
						f = m - 1;
						continue;
					}
					pi res = Get(P + a - m, P + b);
					if(res.fi != get.fi || res.se != get.se)
						f = m - 1;
					else
						r = m + 1, left = a - m;
				}
				r = 0, f = N;
				while(r <= f)
				{
					m = (r + f) / 2;
					if(b + m >= N)
					{
						f = m - 1;
						continue;
					}
					pi res = Get(P + a, P + b + m);
					if(res.fi != get.fi || res.se != get.se)
						f = m - 1;
					else
						r = m + 1, right = b + m;
				}
				if(right - left == y - x)
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
	}
	return 0;
}











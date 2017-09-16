// =====================================================================================
//
//       Filename:  2042.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/28/2016 00:03:08
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
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};
const int MAX_N = 1e6 + 100;

int N, M, K, P;
long long T[MAX_N * 3];

int main() {
	cin >> N >> M >> K;
	for(P=1; P<N; P<<=1);
	for(int i=0; i<N; i++)
		scanf("%lld", &T[P+i]);
	for(int i=P-1; i>=1; i--)
		T[i] = T[i*2] + T[i*2+1];
	for(int o=0; o<M+K; o++)
	{
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if(t == 1)
		{
			int z;
			T[z = P + x - 1] = y;
			while(z/=2) T[z] = T[z*2] + T[z*2+1];
		}
		else
		{
			long long r = 0;
			int a = P+x-1, b = P+y-1;
			while(a<=b)
			{
				if(  a%2) r += T[a++];
				if(1-b%2) r += T[b--];
				a /= 2; b /= 2;
			}
			printf("%lld\n", r);
		}
	}
	return 0;
}











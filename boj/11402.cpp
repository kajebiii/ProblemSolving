// =====================================================================================
//
//       Filename:  11402.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/30/2016 14:32:35
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
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};

long long N, K, M;
long long Fast[4004000];
long long how(long long n, long long m)
{
	long long r = n / m;
	while(n /= m) {r += n/m;}
	return r;
}
long long m0p1(long long a, long long b, long long mod, int type)
{
	long long r = type, p = a;
	while(b)
	{
		if(b%2) {if(type == 0) r += p; else r = m0p1(r, p, mod, 0);}
		r %= mod;
		if(type == 0) p += p; else p = m0p1(p, p, mod, 0);
		p %= mod;
		b /= 2;
	}
	return r;
}
long long getF(long long N, long long mod)
{
	if(N == 0) return 1;
	return m0p1(m0p1(Fast[N%mod], m0p1(mod-1, N/mod, mod, 1), mod, 0), getF(N/mod, mod), mod, 0);
}
int main() {
	cin >> N >> K >> M;
	if(how(N,M) > how(N-K,M) + how(K,M)) {printf("0\n"); return 0;}
	Fast[0] = 1;
	for(int i=1; i<=min(N, M); i++) Fast[i] = m0p1(Fast[i-1], i, M, 0);
	printf("%lld\n", m0p1(getF(N, M), m0p1(m0p1(getF(N-K, M), getF(K, M), M, 0), M-2, M, 1), M, 0));
	return 0;
}











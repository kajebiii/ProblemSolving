// =====================================================================================
//
//       Filename:  9613.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 19:34:27
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

int Nr[111];
int gcd(int a, int b)
{
	return a == 0 ? b : gcd(b%a, a);
}
int main() {
	int N; cin >> N;
	for(; N--;)
	{
		int M; cin >> M;
		long long ans = 0;
		for(int i=0; i<M; i++)
		{
			scanf("%d", &Nr[i]);
			for(int j=0; j<i; j++)
				ans += 1ll * gcd(Nr[j], Nr[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}










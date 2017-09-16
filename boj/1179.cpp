// =====================================================================================
//
//       Filename:  1179.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 13:21:09
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

long long get(long long n, long long k)
{
	if(n == 1) return 0;
	if(k == 1) return n-1;
	if(n < k) return (get(n-1, k) + k) % n;
	long long nn = n - n / k;
	return ((get(nn, k) + nn - n % k) % nn) * k / (k-1);
}

int main() {
	long long N, K; cin >> N >> K;
	cout << get(N, K) + 1;
	return 0;
}











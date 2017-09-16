// =====================================================================================
//
//       Filename:  1215.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 12:15:54
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

int main() {
	int N, K; cin >> N >> K;

	long long result = 0;
	int last = N;
	for(int i=1; i*i <= K; i++)
	{
		int now = K / i + 1;
		int next = i!=1 ?  K / (i-1) : N;
		if(next > N) next = N;
		if(now > next) continue;
		long long be = result;
		result += 1ll * (next - now + 1) * K;
		result -= 1ll * (i-1) * (now + next) * (next - now + 1) / 2;
		last = now - 1;
	}
	for(int i=1; i<=last; i++)
		result += 1ll * (K % i);
	cout << result << endl;
	return 0;
}











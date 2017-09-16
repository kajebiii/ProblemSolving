// =====================================================================================
//
//       Filename:  9047.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 15:35:54
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
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int next(int n)
{
	int cnt = 0, A[4] = {0, 0, 0, 0}; A[0] = n%10;
	while(n/=10) A[++cnt] = n%10;
	sort(A, A+4);
	int maxN = 0, minN = 0;
	for(int i=3; i>=0; i--) maxN *= 10, maxN += A[i], minN *= 10, minN += A[3-i];
	return maxN - minN;
}
int main() {
	int T; cin >> T;
	while(T--)
	{
		int N, Ans = 0; scanf("%d", &N);
		while(N != 6174) N = next(N), Ans++;
		printf("%d\n", Ans);
	}
	return 0;
}











// =====================================================================================
//
//       Filename:  2729.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 01:16:36
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
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		string A, B; cin >> A >> B;
		reverse(A.begin(), A.end()); int AN = A.length();
		reverse(B.begin(), B.end()); int BN = B.length();
		vector<int> V(max(AN, BN) + 10, 0);
		for(int i=0; i<max(AN, BN); i++)
		{
			int a = i<AN ? A[i]-'0' : 0;
			int b = i<BN ? B[i]-'0' : 0;
			V[i+1] += (V[i]+a+b)/2;
			V[i] = (V[i]+a+b)%2;
		}
		bool first = false;
		for(int i=max(AN, BN)+9; i>=0; i--)
		{
			if(V[i] == 1) first = true;
			if(first) printf("%d", V[i]);
		}
		if(first == false) printf("0");
		puts("");
	}
	return 0;
}











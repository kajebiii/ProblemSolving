// =====================================================================================
//
//       Filename:  1560.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 19:54:26
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

int A[99], N;
int main() {
	string S; cin >> S; N = S.length();
	if(N == 1 && S[0] == '1')
	{
		printf("1\n");
		return 0;
	}
	for(int i=0; i<N; i++)
		A[N-1-i] = (S[i] - '0') * 2;
	A[0] -= 2;
	for(int i=0; i<90; i++)
	{
		A[i] += 10; A[i+1] -= 1;
		A[i+1] += A[i] / 10; A[i] %= 10;
	}

	bool first = false;
	for(int i=90; i>=0; i--)
	{
		if(A[i] != 0) first = true;
		if(first) printf("%d", A[i]);
	}
	return 0;
}











// =====================================================================================
//
//       Filename:  8595.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 19:46:25
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

char A[5005005];
int main() {
	ll Ans = 0;
	int N; scanf("%d", &N);
	scanf("%s", A); A[N] = 'a'; N++;

	int now = 0;
	for(int i=0; i<N; i++)
	{
		if(A[i] >= '0' && A[i] <= '9')
		{
			now *= 10;
			now += A[i] - '0';
		}
		else
		{
			Ans += 1ll * now;
			now = 0;
		}
	}
	cout << Ans;
	return 0;
}











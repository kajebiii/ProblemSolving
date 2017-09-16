// =====================================================================================
//
//       Filename:  2331.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 18:50:30
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

int Chk[9999999];

int main() {
	int N, P; cin >> N >> P;
	int cnt = 0;
	while(Chk[N] == 0)
	{
		Chk[N] = ++cnt;
		int n = N; N = 0;
		while(n)
		{
			int now = 1;
			for(int i=0; i<P; i++)
				now *= (n%10);
			N += now;
			n /= 10;
		}
	}
	printf("%d\n", Chk[N]-1);
	return 0;
}











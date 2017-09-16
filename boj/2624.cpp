// =====================================================================================
//
//       Filename:  2624.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 19:29:52
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
const int MAX_T = 11111;

int T, K;
int Dy[2][MAX_T];

int main() {
	cin >> T >> K;
	Dy[0][0] = 1;
	for(int k=1; k<=K; k++)
	{
		for(int i=0; i<=T; i++) Dy[k%2][i] = 0;

		int p, n; scanf("%d%d", &p, &n);
		for(int start=0; start<p; start++)
		{
			int now = 0;
			for(int i=start; i<=T; i+=p)
			{
				now += Dy[1-k%2][i] - ((i-n*p-p >= 0) ? Dy[1-k%2][i-n*p-p] : 0);
				Dy[k%2][i] += now;
			}
		}
	}
	cout << Dy[K%2][T];
	return 0;
}











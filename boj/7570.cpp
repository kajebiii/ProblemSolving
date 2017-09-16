// =====================================================================================
//
//       Filename:  7570.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 23:47:42
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
const int MAX_N = 1e6 + 1000;

int Nr[MAX_N], Dy[MAX_N];
int main() {
	int N; cin >> N;
	for(int x, i=1; i<=N; i++)
	{
		scanf("%d", &x);
		Nr[x] = i;
	}
	int ans = 0;
	for(int i=1; i<=N; i++)
	{
		Dy[i] = 1;
		if(Nr[i-1] < Nr[i]) 
			Dy[i] = Dy[i-1] + 1;
		ans = max(ans, Dy[i]);
	}
	cout << N - ans;
	return 0;
}











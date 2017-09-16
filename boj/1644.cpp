// =====================================================================================
//
//       Filename:  1644.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 20:20:02
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
const int MAX_N = 4e6 + 400;

bool notP[MAX_N];
ll Sum[MAX_N], SN;

int main() {
	int N; cin >> N;
	notP[1] = true;
	for(int i=2; i<=N; i++)
		if(notP[i] == false)
		{
			SN++; Sum[SN] = Sum[SN-1] + 1ll*i;
			for(int j=i*2; j<=N; j+=i) notP[j] = true;
		}
	
	int ans = 0;
	for(int i=1; i<=SN; i++)
	{
		if(Sum[i] < N) continue;
		int ix = (int)(lower_bound(Sum, Sum+SN, Sum[i] - N) - Sum);
		if(Sum[ix] == Sum[i]-N) ans++;
	}

	cout << ans;

	return 0;
}











// =====================================================================================
//
//       Filename:  1509.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/13/2016 16:37:03
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

char S[5555];
int Dy[2555], F[5555];
int main() {
	scanf("%s", S+1); int N = (int)strlen(S+1);
	for(int i=N; i>=1; i--) S[i*2] = S[i], S[i*2-1] = '#';

	int m = 0, r = 0;
	for(int i=1; i<=N; i++) Dy[i] = INF;
	Dy[0] = 0;
	for(int i=2; i<=N*2; i++)
	{
		if(i <= r) F[i] = min(F[2*m-i], r-i);
		else F[i] = 0;
		while(i-F[i]-1>=2 && i+F[i]+1<=N*2 && S[i-F[i]-1] == S[i+F[i]+1]) F[i]++;
		int sl = (i-F[i]+1) / 2, sr = (i+F[i]) / 2;
		while(sl <= sr)
		{
			Dy[sr] = min(Dy[sr], Dy[sl-1] + 1);
			sl++; sr--;
		}
	}
	cout << Dy[N];
	return 0;
}











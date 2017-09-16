// =====================================================================================
//
//       Filename:  12780.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/10/2016 21:20:18
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
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int SN, AN, F[22];
char S[22], A[101101];
int main() {
	scanf("%s", A); AN = (int)strlen(A);
	scanf("%s", S); SN = (int)strlen(S);
	F[0] = -1; for(int i=0, j=-1; i<SN; j<0||S[i]==S[j]?F[++i]=++j:j=F[j]);
	int ans = 0;
	for(int i=0, j=0; i<AN;)
	{
		if(j < 0 || A[i] == S[j])
		{
			i++; j++;
			if(j == SN) {ans++; j = F[j];}
		}
		else j = F[j];
	}
	cout << ans;
	return 0;
}











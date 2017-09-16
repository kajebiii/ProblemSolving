// =====================================================================================
//
//       Filename:  2529.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 17:14:44
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

char V[22]; int N, Nr[22], Chk[22];

bool getAns(int n, int p)
{
	if(n == N+1)
	{
		for(int i=0; i<n; i++) printf("%d", Nr[i]); printf("\n");
		return true;
	}
	int CS[2] = {0, 9}, CP[2] = {1, -1};
	for(int i = CS[p]; i!=-1 && i!=10; i+=CP[p])
	{
		if(Chk[i] == 1) continue;
		Nr[n] = i; Chk[i] = 1;
		if(n == 0 || (V[n-1]=='<' && Nr[n-1] < Nr[n]) || (V[n-1]=='>' && Nr[n-1] > Nr[n]))
			if(getAns(n+1, p)) return true;
		Chk[i] = 0;
	}
	return false;
}
int main() {
	scanf("%d\n", &N); for(int i=0; i<N; i++) scanf("%c ", &V[i]);
	getAns(0, 1); for(int i=0; i<=N; i++) Chk[i] = 0; getAns(0, 0);
	return 0;
}











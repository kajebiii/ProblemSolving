// =====================================================================================
//
//       Filename:  9575.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/10/2016 20:54:34
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

bool isLucky(int a)
{
	do{if(a%10!=5 && a%10!=8) return false;}while(a/=10);
	return true;
}
bool Chk[99999];
int main() {
	int T; cin >> T;
	while(T--)
	{
		int A[3], Nr[3][55];
		for(int k=0; k<3; k++)
		{
			scanf("%d", &A[k]);
			for(int i=0; i<A[k]; i++)
				scanf("%d", &Nr[k][i]);
		}

		int ans = 0;
		for(int i=0; i<99999; i++) Chk[i] = false;
		for(int i=0; i<A[0]; i++) for(int j=0; j<A[1]; j++) for(int k=0; k<A[2]; k++)
		{
			int now = Nr[0][i] + Nr[1][j] + Nr[2][k];
			if(Chk[now] == false && isLucky(now))
			{
				Chk[now] = true;
				ans++;
			}
		}
		printf("%d\n", ans);
		
	}
	return 0;
}











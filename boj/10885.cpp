// =====================================================================================
//
//       Filename:  10885.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 17:13:09
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
#include <stdlib.h>

using namespace std;

typedef pair<int, int> pi;
#define mp make_pair
#define fi first
#define se second

const int MAX_N = 1e5 + 100;
const int INF = 0x7fffffff;
const int MOD = 1e9 + 7;

int N, Nr[MAX_N];
int Dy[MAX_N][2];
int P[MAX_N];

int main() {
	int T; cin >> T;
	P[0] = 1;
	for(int i=1; i<MAX_N; i++)
		P[i] = P[i-1] * 2, P[i] %= MOD;
	for(; T--; )
	{
		scanf("%d", &N);
		Nr[0] = Nr[N+1] = 0;
		for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);

		int Ans = -INF;
		Dy[0][0] = -INF; Dy[0][1] = -INF;
		for(int i=1; i<=N+1; i++)
		{
			if(Nr[i] == 0)
			{
				for(int j=i-1; Nr[j]!=0; j--)
					Ans = max(Ans, Dy[j][0]);
				Dy[i][0] = -INF; Dy[i][1] = -INF;
				continue;
			}
			int cp[2] = {0, 1}, cm[2] = {1, -1};
			int k = (Nr[i] > 0) ? 0 : 1;
			int x = (abs(Nr[i]) == 1) ? 0 : 1;
			for(int j=0; j<2; j++)
				Dy[i][j] = Dy[i-1][cp[k] + cm[k] * j] + x;
			Dy[i][k] = max(Dy[i][k], x);
		}
		
		if(Ans >= 0)
			printf("%d\n", P[Ans]);
		else
			printf("0\n");
	}
	return 0;
}









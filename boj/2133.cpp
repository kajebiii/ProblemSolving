// =====================================================================================
//
//       Filename:  2133.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 13:18:11
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

#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

long long Dy[55][8];
int main() {
	int N; cin >> N;
	Dy[1][0] = Dy[1][1+2] = Dy[1][2+4] = 1;
	for(int i=2; i<=N; i++)
	{
		for(int j=0; j<8; j++)
		{
			int now = 0;
			for(int k=0; k<3; k++)
			{
				if( (j & (1<<k)) == 0 )
					now += 1<<k;
			}
			Dy[i][now] += Dy[i-1][j];
			if( (now & 3) == 0)
				Dy[i][now | 3] += Dy[i-1][j];
			if( (now & 6) == 0)
				Dy[i][now | 6] += Dy[i-1][j];
		}
	}
	printf("%lld\n", Dy[N][7]);
	return 0;
}











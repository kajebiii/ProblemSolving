// =====================================================================================
//
//       Filename:  2096.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/21/2016 17:37:37
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

using namespace std;

typedef pair<int, int> pi;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;

int Dy[2][3][2];

int main() {
	int N; cin >> N;
	for(int i=0; i<N; i++)
	{
		int A[3]; for(int j=0; j<3; j++) scanf("%d", &A[j]);
		for(int j=0; j<3; j++)
			Dy[i%2][j][0] = 0, Dy[i%2][j][1] = INF;
		int theMin = INF, theMax = 0;
		for(int j=0; j<3; j++)
		{
			for(int k=-1; k<=1; k++)
			{
				if(j + k < 0 || j + k > 2) continue;
				Dy[i%2][j][0] = max(Dy[i%2][j][0], Dy[1-i%2][j+k][0] + A[j]);
				theMax = max(theMax, Dy[i%2][j][0]);
				Dy[i%2][j][1] = min(Dy[i%2][j][1], Dy[1-i%2][j+k][1] + A[j]);
				theMin = min(theMin, Dy[i%2][j][1]);
			}
		}
		if(i+1 == N)
			cout << theMax << " " << theMin;
	}
	return 0;
}











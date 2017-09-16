// =====================================================================================
//
//       Filename:  2863.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 10:10:51
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

#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

struct MET
{
	int A[4]; // [[0, 1], [3, 2] ]
	int index;
	const bool operator<(const MET &o) const
	{
		int X = (A[0] * A[2] + A[3] * A[1]) * (o.A[2] * o.A[3]);
		int Y = (o.A[0] * o.A[2] + o.A[3] * o.A[1]) * (A[2] * A[3]);
		if(X == Y)
			return index < o.index;
		return X > Y;
	}
}M[4];

int main() {
	cin >> M[0].A[0] >> M[0].A[1] >> M[0].A[3] >> M[0].A[2]; M[0].index = 0;
	for(int i=1; i<4; i++)
	{
		for(int j=0; j<4; j++)
			M[i].A[j] = M[i-1].A[(j+3)%4];
		M[i].index = i;
	}
	sort(M, M+4);
	cout << M[0].index;
	return 0;
}











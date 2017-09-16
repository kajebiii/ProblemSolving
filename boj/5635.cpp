// =====================================================================================
//
//       Filename:  5635.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 13:10:30
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
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};

struct INFO
{
	string S;
	int A[3];
	const bool operator<(const INFO &o) const
	{
		for(int i=2; i>=0; i--)
			if(A[i] != o.A[i])
				return A[i] < o.A[i];
		return false;
	}
}I[111];

int main() {
	int N; cin >> N;
	for(int i=0; i<N; i++)
	{
		cin >> I[i].S;
		for(int j=0; j<3; j++)
			scanf("%d", &I[i].A[j]);
	}
	sort(I, I+N);
	cout << I[N-1].S << endl << I[0].S;
	return 0;
}











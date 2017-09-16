// =====================================================================================
//
//       Filename:  10997.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 14:56:03
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
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, 1, 0, -1};

bool Map[800][800];

int main() {
	int N; cin >> N;
	if(N == 1)
	{
		printf("*\n");
		return 0;
	}
	int x = 2*N, y = 2*N-2, d = 0;
	Map[x][y] = 1;
	for(int k=1; k<=2*N-1; k++)
	{
		int go = k*2;
		for(int j=0; j<2; j++, d = (d+1)%4)
			for(int i=0; i<go; i++)
			{
				x += CX[d];
				y += CY[d];
				Map[x][y] = 1;
			}
	}
	for(int i=0; i<4*N-1; i++)
	{
		int k = 0;
		for(int j=4*N-4; j>=0; j--)
			if(Map[i][j])
			{
				k = j;
				break;
			}
		string S;
		for(int j=0; j<=k; j++)
			if(Map[i][j]) S += '*';
			else S += ' ';
		cout << S;
		puts("");
	}
	return 0;
}











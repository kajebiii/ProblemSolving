// =====================================================================================
//
//       Filename:  1992.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 00:12:44
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

const int MAX_N = 100;

int N, Nr[MAX_N][MAX_N];

void DFS(int x0, int x1, int y0, int y1)
{
	int m = (x1 - x0) / 2;
	if(m == 0)
	{
		printf("%d", Nr[x0][y0]);
		return;
	}
	printf("(");
	for(int p=0; p<4; p++)
	{
		int px = p / 2, py = p % 2;
		bool check[2] = {false, false};
		int nx0 = x0+px*m, nx1 = nx0+m, ny0 = y0+py*m, ny1 = ny0+m;
		for(int i=nx0; i<nx1; i++)
			for(int j=ny0; j<ny1; j++)
				check[Nr[i][j]] = true;
		if(check[0] & check[1])
			DFS(nx0, nx1, ny0, ny1);
		else
		{
			for(int i=0; i<2; i++)
				if(check[i]) printf("%d", i);
		}
	}
	printf(")");
}

int main() {
	cin >> N;
	bool check[2] = {false, false};
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%1d", &Nr[i][j]), check[Nr[i][j]] = true;
	if(check[0] && check[1])
		DFS(0, N, 0, N);
	else
	{
		for(int i=0; i<2; i++)
			if(check[i]) printf("%d", i);
	}
	return 0;
}











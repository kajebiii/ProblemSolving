// =====================================================================================
//
//       Filename:  1913.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 13:08:10
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

const int MAX_N = 1111;

int N, Nr[MAX_N][MAX_N], Find;

int main() {
	cin >> N >> Find;

	int cnt = 0;
	int x, y; x = y = (N+1)/2;
	Nr[x][y] = ++cnt;
	
	int cx[4] = {-1, 0, 1, 0}, cy[4] = {0, 1, 0, -1};
	int d = 0;
	
	int ansX = x, ansY = y;
	for(int i=1; i<=N; i++)
	{
		for(int k=0; k<2; k++, d = (d+1)%4)
			for(int j=1; j<=i; j++)
			{
				x += cx[d], y += cy[d];
				if(x <= 0 || y <= 0 || x > N || y > N) continue;
				Nr[x][y] = ++cnt;
				if(Nr[x][y] == Find)
					ansX = x, ansY = y;
			}
		if(cnt == (N*N))
			break;
	}

	for(int i=1; i<=N; i++, printf("\n")) for(int j=1; j<=N; printf("%d ", Nr[i][j++]));
	printf("%d %d\n", ansX, ansY);

	return 0;
}











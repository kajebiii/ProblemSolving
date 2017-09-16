// =====================================================================================
//
//       Filename:  2281.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 19:13:07
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e3 + 10;
const int INF = 0x7fffffff;

int N, M;
int Nr[MAX_N];
int Dy[MAX_N][MAX_N];

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++)
		cin >> Nr[i];
	for(int i=0; i<=N; i++)
		for(int j=0; j<=M; j++)
			Dy[i][j] = INF;
	Dy[1][Nr[1]] = 0;

	for(int i=2; i<=N; i++)
	{
		for(int j=0; j<=M-Nr[i]-1; j++)
			if(Dy[i-1][j] != INF)
				Dy[i][j+Nr[i]+1] = min(Dy[i][j+Nr[i]+1], Dy[i-1][j]);
		int newLine = INF;
		for(int j=0; j<=M; j++)
			if(Dy[i-1][j] != INF)
				newLine = min(newLine, Dy[i-1][j] + (M-j) * (M-j));
		Dy[i][Nr[i]] = min(Dy[i][Nr[i]], newLine);
	}

	printf("%d\n", Dy[N][min_element(Dy[N], Dy[N]+M+1) - Dy[N]]);

	return 0;
}
























// =====================================================================================
//
//       Filename:  1793.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 20:26:54
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

const int MOD = 1e4 + 7;

vector<int> Dy[1111];

int main() {
	int N = 250;
	for(int i=0; i<=N; i++)
		Dy[i] = vector<int>(250, 0);
	
	Dy[0][0] = Dy[1][0] = 1;
	for(int i=2; i<=N; i++)
	{
		for(int j=0; j<250-1; j++)
		{
			Dy[i][j] += Dy[i-1][j] + Dy[i-2][j] * 2;
			Dy[i][j+1] += Dy[i][j]/10;
			Dy[i][j] %= 10;
		}
	}

	int K;
	while(scanf("%d", &K) != EOF)
	{
		bool flag = false;
		for(int i=249; i>=0; i--)
		{
			if(Dy[K][i] != 0) flag = true;
			if(flag)
				cout << Dy[K][i];
		}
		cout << endl;
	}
	return 0;
}











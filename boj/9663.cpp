// =====================================================================================
//
//       Filename:  9663.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/24/2016 00:04:03
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

int N, C[22], Ans;

void DFS(int k)
{
	if(k == N)
		Ans++;
	for(int i=0; i<N; i++)
	{
		bool flag = true;
		for(int j=0; j<k; j++)
			if(C[j] == i || abs(C[j] - i) == k - j)
			{
				flag = false;
				break;
			}
		if(flag)
		{
			C[k] = i;
			DFS(k+1);
		}
	}
}

int main() {
	cin >> N;
	DFS(0);
	cout << Ans;
	return 0;
}











// =====================================================================================
//
//       Filename:  11403.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 20:04:55
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

int Ans[111][111];
int V[111][111];
int N;

int main() {
	cin >> N;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin >> V[i][j];
	for(int i=0; i<N; i++)
	{
		queue<int> Q;
		while(!Q.empty()) Q.pop();
		Q.push(i);
		while(!Q.empty())
		{
			int now = Q.front(); Q.pop();
			for(int j=0; j<N; j++)
			{
				if(Ans[i][j] == 1) continue;
				if(V[now][j] == 0) continue;
				Ans[i][j] = 1;
				Q.push(j);
			}
		}
	}
	for(int i=0; i<N; i++, cout << endl)
		for(int j=0; j<N; j++)
			printf("%d ", Ans[i][j]);
	return 0;
}











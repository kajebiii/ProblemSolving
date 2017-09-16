// =====================================================================================
//
//       Filename:  2448.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 13:22:38
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

bool Map[3*(1<<10)][3*(1<<10)*2];
int main() {
	int N; cin >> N;
	int x = 0, y = N - 1;
	Map[x][y] = Map[x+1][y-1] = Map[x+1][y+1] = true;
	for(int i=-2; i<=2; i++) Map[x+2][y+i] = true;
	int now = 3;

	while(now < N)
	{
		int a, b;
		for(int k=0; k<2; k++)
		{
			a = x + now;
			if(k == 0)
				b = y - now;
			else
				b = y + now;
			for(int i=0; i<now; i++) for(int j=-now+1; j<=now-1; j++)
				Map[a+i][b+j] = Map[x+i][y+j];
		}
		now *= 2;
	}
	for(int i=0; i<N; i++, printf("\n")) 
	{
		string S = "";
		for(int j=0; j<N*2; j++)
			S += Map[i][j]?'*':' ';
		cout << S;
	}
	return 0;
}











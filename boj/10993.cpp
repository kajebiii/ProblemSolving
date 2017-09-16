// =====================================================================================
//
//       Filename:  10993.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 14:34:25
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

bool Map[1<<11][1<<11];
void Draw(int a, int b, int n)
{
	if(n == 0) return;
	if(n % 2 == 0)
	{
		for(int i=0; i<(1<<n)-1; i++)
			Map[a-i][b-i] = Map[a-i][b+i] =
			Map[a-(1<<n)+2][b-i] = Map[a-(1<<n)+2][b+i] = 1;
		Draw(a-(1<<n)+2+1, b, n-1);
	}
	else
	{
		for(int i=0; i<(1<<n)-1; i++)
			Map[a+i][b-i] = Map[a+i][b+i] =
			Map[a+(1<<n)-2][b-i] = Map[a+(1<<n)-2][b+i] = 1;
		Draw(a+(1<<n)-2-1, b, n-1);
	}
}
int main() {
	int N; cin >> N;
	if(N % 2 == 1)
		Draw(0, (1<<N) - 2, N);
	else
		Draw((1<<N) - 2, (1<<N) - 2, N);
	for(int i=0; i<(1<<N)-1; i++) 
	{
		string S;
		int k = 0;
		for(int j=(1<<(N+1))-1; j>=0; j--)
			if(Map[i][j]) 
			{
				k = j;
				break;
			}
		for(int j=0; j<=k; j++)
			if(Map[i][j]) S += '*';
			else S += ' ';
		cout << S << endl;
	}
	return 0;
}











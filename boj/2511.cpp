// =====================================================================================
//
//       Filename:  2511.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 19:39:23
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

int S[2][2];
int main() {
	int A[2][10];
	for(int j=0; j<2; j++) for(int i=0; i<10; i++)
		cin >> A[j][i];
	for(int i=0; i<10; i++)
	{
		if(A[0][i] == A[1][i])
		{
			S[0][0]++;
			S[1][0]++;
		}
		else if(A[0][i] > A[1][i])
		{
			S[0][0]+=3;
			S[0][1] = i+1;
		}
		else
		{
			S[1][0]+=3;
			S[1][1] = i+1;
		}
	}
	cout << S[0][0] << " " << S[1][0] << endl;
	if(S[0][0] == S[1][0])
	{
		if(S[0][1] == S[1][1]) puts("D");
		else if(S[0][1] > S[1][1]) puts("A");
		else puts("B");
	}
	else if(S[0][0] > S[1][0]) puts("A");
	else puts("B");
	return 0;
}











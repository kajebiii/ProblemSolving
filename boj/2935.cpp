// =====================================================================================
//
//       Filename:  2935.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/27/2016 22:15:14
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

int main() {
	string A, B; char c;
	cin >> A; cin >> c; cin >> B;
	if(c == '*')
	{
		printf("1");
		for(int i=0; i<(int)A.length() + B.length() - 2; i++)
			printf("0");
	}
	else
	{
		if(A.length() == B.length())
		{
			printf("2");
			for(int i=0; i<(int)A.length() - 1; i++)
				printf("0");
		}
		else
		{
			for(int i=max(A.length(), B.length())-1; i>=0; i--)
			{
				if(i == (int)A.length() - 1 || i == (int)B.length() - 1)
					printf("1");
				else
					printf("0");
			}
		}
	}
	return 0;
}











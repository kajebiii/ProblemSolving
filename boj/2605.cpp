// =====================================================================================
//
//       Filename:  2605.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 20:14:23
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

int N, Nr[111];
int Ans[111];

int main() {
	cin >> N;
	for(int i=1; i<=N; i++) cin >> Nr[i];
	for(int i=N; i>=1; i--)
	{
		for(int j=N; j>=1; j--)
		{
			if(Ans[j] != 0) continue;
			if(Nr[i]-- == 0)
			{
				Ans[j] = i;
				break;
			}
		}
	}
	for(int i=1; i<=N; i++)
		cout << Ans[i] << " ";
	return 0;
}











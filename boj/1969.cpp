// =====================================================================================
//
//       Filename:  1969.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 16:32:15
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

const int MAX_N = 1000;

map<char, int> CI;
map<int, char> IC;

int N, M;
string S[MAX_N];

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++)
		cin >> S[i];

	CI['A'] = 0, CI['C'] = 1, CI['G'] = 2, CI['T'] = 3;
	IC[0] = 'A', IC[1] = 'C', IC[2] = 'G', IC[3] = 'T';

	int result = 0;
	for(int j=0; j<M; j++)
	{
		int T[4] = {0, 0, 0, 0};
		for(int i=0; i<N; i++)
			T[CI[S[i][j]]]++;
		int maxIndex = distance(T, max_element(T, T+4));
		printf("%c", IC[maxIndex]);
		result += accumulate(T, T+4, 0) - T[maxIndex];
	}
	printf("\n%d\n", result);
	return 0;
}

















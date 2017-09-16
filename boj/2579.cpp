// =====================================================================================
//
//       Filename:  2579.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 21:28:24
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

using namespace std;

int N, Nr[555];
int Dy[555][2];

int main() {
	cin >> N;
	for(int i=1; i<=N; i++) cin >> Nr[i];
	Dy[1][0] = Nr[1];
	Dy[2][0] = Nr[1] + Nr[2];
	Dy[2][1] = Nr[2];
	for(int i=3; i<=N; i++)
	{
		Dy[i][1] = max(Dy[i][1], Nr[i] + max(Dy[i-2][1], Dy[i-2][0]));
		Dy[i][0] = max(Dy[i][0], Nr[i] + Dy[i-1][1]);
	}
	printf("%d\n", max(Dy[N][0], Dy[N][1]));
	return 0;
}











// =====================================================================================
//
//       Filename:  2156.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 17:26:14
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

int Nr[11111];
int Dy[11111];

int main() {
	int N; cin >> N;
	for(int i=1; i<=N; i++)
		cin >> Nr[i];
	Dy[0] = 0; Dy[1] = Nr[1]; Dy[2] = Nr[2] + Nr[1];
	for(int i=3; i<=N; i++)
		Dy[i] = max(Dy[i-1], max(Dy[i-3] + Nr[i-1] + Nr[i], Dy[i-2] + Nr[i]));
	cout << Dy[max_element(Dy+1, Dy+N+1) - Dy];
	return 0;
}











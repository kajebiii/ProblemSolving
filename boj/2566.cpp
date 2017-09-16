// =====================================================================================
//
//       Filename:  2566.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 16:54:48
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

int Nr[9][9];

int main() {
	for(int i=0; i<9; i++) for(int j=0; j<9; j++) cin >> Nr[i][j];
	int index = (int)(max_element(&Nr[0][0], &Nr[10][0]) - &Nr[0][0]);
	cout << *(&Nr[0][0]+index) << endl << index / 9 + 1 << " " << index % 9 + 1<< endl;
	return 0;
}











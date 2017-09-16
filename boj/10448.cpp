// =====================================================================================
//
//       Filename:  10448.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 15:26:11
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

int Chk[1111], T[55];
int main() {
	for(int i=1; i<=50; i++) T[i] = T[i-1] + i;
	for(int i=1; i<=50; i++) for(int j=i; j<=50; j++) for(int k=j; k<=50; k++)
		if(T[i]+T[j]+T[k] <= 1000) Chk[T[i]+T[j]+T[k]] = 1;
	int K; cin >> K;
	for(int x; K--;)
		cin >> x, cout << Chk[x] << endl;
	return 0;
}











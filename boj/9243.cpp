// =====================================================================================
//
//       Filename:  9243.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 19:27:57
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
#include <math.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};

char A[2][1111];
int main() {
	int K; cin >> K;	
	for(int i=0; i<2; i++) scanf("%s", A[i]);
	int N = (int)strlen(A[0]);
	int CP[2] = {0, 1}, CT[2] = {1, -1};
	bool flag = true;
	for(int i=0; i<N; i++)
		if(A[0][i]-'0' != (CP[K%2] + CT[K%2]*(A[1][i]-'0') ))
			flag = false;
	if(flag)
		puts("Deletion succeeded");
	else
		puts("Deletion failed");
	return 0;
}











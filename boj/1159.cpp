// =====================================================================================
//
//       Filename:  1159.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 23:14:04
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
const int MAX_N = 222;

int N;
string S[MAX_N];

int main() {
	cin >> N;
	for(int i=0; i<N; i++) cin >> S[i];
	sort(S, S+N);

	bool find = false;
	int cnt = 0;
	for(int i=0; i<N; i++)
	{
		if(i == 0 || S[i][0] != S[i-1][0]) cnt = 0;
		cnt++;
		if(i == N-1 || S[i][0] != S[i+1][0])
			if(cnt >= 5)
			{
				printf("%c", S[i][0]);
				find = true;
			}
	}
	if(!find)
		puts("PREDAJA");
	return 0;
}











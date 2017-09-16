// =====================================================================================
//
//       Filename:  1181.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 12:23:58
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
const int MAX_N = 2e4 + 200;

int N;
string S[MAX_N];
bool cmp(string A, string B)
{
	if(A.length() != B.length()) return A.length() < B.length();
	return A < B;
}

int main() {
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> S[i];
	sort(S, S+N, cmp);
	for(int i=0; i<N; i++)
		if(i == 0 || S[i-1] != S[i])
			cout << S[i] << endl;

	return 0;
}











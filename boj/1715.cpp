// =====================================================================================
//
//       Filename:  1715.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 01:03:10
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

priority_queue<int, vector<int>, greater<int> > Q;

int main() {
	int N; cin >> N;
	int Ans = 0;
	for(int x; N--;) scanf("%d", &x), Q.push(x);
	while(Q.size() > 1)
	{
		int a = Q.top(); Q.pop();
		int b = Q.top(); Q.pop();
		int c = a + b; Q.push(c);
		Ans += c;
	}
	cout << Ans;
	return 0;
}











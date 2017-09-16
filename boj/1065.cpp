// =====================================================================================
//
//       Filename:  1065.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 18:11:01
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

bool isHanSoo(int x)
{
	vector<int> V;
	for(; x; x/=10) V.push_back(x%10);
	int sum = V[0] + V[V.size()-1];
	for(int i=0; i<V.size(); i++)
		if(V[i] + V[V.size()-1-i] != sum)
			return false;
	return true;
}

int main() {
	int N; cin >> N;
	int ans = 0;
	for(int i=1; i<=N; i++) 
		if(isHanSoo(i)) ans++;
	cout << ans;
	return 0;
}











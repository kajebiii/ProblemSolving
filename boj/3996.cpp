// =====================================================================================
//
//       Filename:  3996.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 16:52:28
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

long long N, K;
vector<int> V, SV;

int main() {
	cin >> N >> K;
	while(N)
	{
		V.push_back(N % K);
		N /= K;
	}
	for(int i = (int)V.size() - 1; i >= 0; i--)
	{
		if(i % 2 == 1 && V[i] > 0)
		{
			for(int j=i-1; j>=0; j-=2)
				SV.push_back(K-1);
			break;
		}
		if(i % 2 == 0)
			SV.push_back(V[i]);
	}
	reverse(SV.begin(), SV.end());
	
	long long pow = 1;
	long long ans = 0;
	for(int i=0; i<SV.size(); i++)
	{
		if(i == 0) ans++;
		ans += SV[i] * pow;
		pow *= K;
	}
	cout << ans;
	return 0;
}











// =====================================================================================
//
//       Filename:  5618.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 17:00:58
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

int gcd(int a, int b) {return a?gcd(b%a,a):b;}
int N, Ans = 0;
int main() {
	cin >> N;
	while(N--)
	{
		int x; scanf("%d", &x);
		Ans = gcd(Ans, x);
	}
	vector<int> All;
	for(int i=1; i*i<=Ans; i++)
		if(Ans % i == 0)
			All.push_back(i), All.push_back(Ans/i);
	sort(All.begin(), All.end());
	N = unique(All.begin(), All.end()) - All.begin();
	All.resize(N);
	for(int x : All) printf("%d\n", x);
	return 0;
}











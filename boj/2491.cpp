// =====================================================================================
//
//       Filename:  2491.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 21:16:54
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
const int MAX_N = 1e5 + 100;

int N, Nr[MAX_N];
int Dy[MAX_N];

int get() 
{
	Dy[0] = 1;
	int ans = 1;
	for(int i=1; i<N; i++)
	{
		Dy[i] = 1;
		if(Nr[i] >= Nr[i-1]) Dy[i] = Dy[i-1] + 1;
		ans = max(ans, Dy[i]);
	}
	return ans;
}

int main() {
	scanf("%d", &N); for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	int ans = 0;
	ans = max(ans, get());
	reverse(Nr, Nr+N);
	ans = max(ans, get());
	cout << ans;
	return 0;
}











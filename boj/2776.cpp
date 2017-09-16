// =====================================================================================
//
//       Filename:  2776.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 20:03:34
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

int Nr[1111111];
int main() {
	int T; cin >> T;
	while(T--)
	{
		set<int> S;
		int N; scanf("%d", &N);
		for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
		sort(Nr, Nr+N);
		int M; scanf("%d", &M);
		for(int i=0; i<M; i++)
		{
			int x; scanf("%d", &x);
			int diff = (int)(upper_bound(Nr, Nr+N, x) - lower_bound(Nr, Nr+N, x));
			if(diff) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}











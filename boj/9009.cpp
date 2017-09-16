// =====================================================================================
//
//       Filename:  9009.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 16:57:52
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

int Fibo[50];
void get(int n, int k)
{
	if(k == 0) return;
	if(n >= Fibo[k])
	{
		get(n-Fibo[k], k-1);
		printf("%d ", Fibo[k]);
	}
	else
		get(n, k-1);
}
int main() {
	int T; cin >> T;
	Fibo[0] = 0; Fibo[1] = 1;
	for(int i=2; i<45; i++)
		Fibo[i]=Fibo[i-1]+Fibo[i-2];
	while(T--)
	{
		int N; scanf("%d", &N);
		get(N, 44);
		printf("\n");
	}
	return 0;
}











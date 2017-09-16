// =====================================================================================
//
//       Filename:  9417.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 19:34:27
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

int Nr[111];
int gcd(int a, int b)
{
	return a == 0 ? b : gcd(b%a, a);
}
int main() {
	int N; scanf("%d\n", &N);
	for(; N--;)
	{
		string S; getline(cin, S);
		int i = 0, cnt = 0;
		while(i < S.length())
		{
			int now = 0;
			while(i < S.length() && S[i] != ' ')
				now *= 10, now += (S[i++] - '0');
			Nr[cnt++] = now;
			i++;
		}
		int ans = 0;
		for(int i=0; i<cnt; i++) for(int j=i+1; j<cnt; j++)
			ans = max(ans, gcd(Nr[i], Nr[j]));
		printf("%d\n", ans);
	}
	return 0;
}










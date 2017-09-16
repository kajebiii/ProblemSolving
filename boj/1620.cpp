// =====================================================================================
//
//       Filename:  1620.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 17:07:51
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

int N, M;
map<string, string> Map;
char Name[33];
int main() {
	cin >> N >> M;
	for(int i=1; i<=N; i++)
	{
		scanf("%s", Name);
		string S = string(Name);
		Map[to_string(i)] = S;
		Map[S] = to_string(i);
	}
	while(M--)
	{
		scanf("%s", Name);
		string S = string(Name);
		const char *c = Map[S].c_str();
		printf("%s\n", c);
	}
	return 0;
}











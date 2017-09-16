// =====================================================================================
//
//       Filename:  2504.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/27/2016 22:28:25
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

int get(string S)
{
	if(S == "") return 1;
	string A = "";
	int ans = 0, a = 0, b = 0;
	bool first = true;
	for(char x : S)
	{
		if(x == '(') a++;
		if(x == ')') a--;
		if(x == '[') b++;
		if(x == ']') b--;
	}
	if(a != 0 || b != 0)
		return 0;
	for(char x : S)
	{
		if(x == '(') a++;
		if(x == ')') a--;
		if(x == '[') b++;
		if(x == ']') b--;
		if(a == 0 && b == 0)
		{
			ans += get(A) * ((x == ']') ? 3 : 2);
			A = "";
			first = true;
			continue;
		}
		if(!first) A += x;
		first = false;
	}
	return ans;
}

int main() {
	string S; cin >> S;
	printf("%d\n", get(S));
	return 0;
}











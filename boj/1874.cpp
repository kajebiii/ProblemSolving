// =====================================================================================
//
//       Filename:  1874.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 17:04:36
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

vector<char> V;
deque<int> S;
int main() {
	int N; cin >> N;
	bool flag = true;
	int now = 1;
	S.push_front(0);
	for(int i=0; i<N; i++)
	{
		int x; scanf("%d", &x);
		if(S.front() == x)
		{
			S.pop_front();
			V.push_back('-');
		}
		else if(S.front() > x)
		{
			flag = false;
			break;
		}else
		{
			for(; now <= x; now++)
				S.push_front(now), V.push_back('+');
			S.pop_front();
			V.push_back('-');
		}
	}
	if(flag == false)
	{
		puts("NO");
		return 0;
	}
	for(char x : V)
		printf("%c\n", x);
	
	return 0;
}











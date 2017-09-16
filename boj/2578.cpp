// =====================================================================================
//
//       Filename:  2578.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 16:18:14
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

bool Map[5][5];
pi Index[99];

bool isBingo()
{
	int cnt = 0;
	bool flag;
	flag = true;
	for(int i=0; i<5; i++)
		if(!Map[i][i]) flag = false;
	cnt += flag;
	flag = true;
	for(int i=0; i<5; i++)
		if(!Map[i][4-i]) flag = false;
	cnt += flag;
	for(int i=0; i<5; i++)
	{
		flag = true;
		for(int j=0; j<5; j++)
			if(!Map[i][j]) flag = false;
		cnt += flag;
		flag = true;
		for(int j=0; j<5; j++)
			if(!Map[j][i]) flag = false;
		cnt += flag;
	}
	return cnt >= 3;
}

int main() {
	for(int i=0; i<5; i++) for(int j=0; j<5; j++)
	{
		int x; cin >> x;
		Index[x] = mp(i, j);
	}
	for(int i=0; i<25; i++)
	{
		int x; cin >> x;
		Map[Index[x].fi][Index[x].se] = true;
		if(isBingo())
		{
			printf("%d\n", i+1);
			break;
		}
	}
	return 0;
}










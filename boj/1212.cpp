// =====================================================================================
//
//       Filename:  1212.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 21:51:39
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

#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

void get(int x, int p, int v)
{
	if(p == 3) return;
	if(v && x == 0) return;
	get(x/2, p+1, v);
	printf("%d", x%2);
}

int main()
{
	int n, cnt = 0;
	while(scanf("%1d", &n) != EOF)
	{
		if(cnt == 0 && n == 0)
		{
			printf("0");
			continue;
		}
		if(cnt++ == 0)
			get(n, 0, 1);
		else
			get(n, 0, 0);
	}
	return 0;
}











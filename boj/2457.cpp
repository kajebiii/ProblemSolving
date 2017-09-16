// =====================================================================================
//
//       Filename:  2457.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/12/2016 20:44:05
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 10;

struct NODE
{
	int s, e;
	const bool operator<(const NODE &other) const
	{
		return s < other.s;
	}
}Nr[MAX_N];


int Days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int N;

int getNr(int x, int y)
{
	int result = 0;
	for(int i=1; i<x; i++)
		result += Days[i];
	result += y;

	return result;
}

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		int x0, y0, x1, y1;
		scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
		Nr[i].s = getNr(x0, y0);
		Nr[i].e = getNr(x1, y1) - 1;
	}
	
	sort(Nr, Nr + N);
	
	int start = getNr(3, 1);
	int maxEnd = -1;
	int result = 0, pivot = 0;

	while(pivot < N)
	{
		int last = pivot;
		while(Nr[pivot].s <= start && pivot < N)
			maxEnd = max(maxEnd, Nr[pivot++].e);
		result++;
		if(maxEnd >= getNr(11, 30))
		{
			printf("%d\n", result);
			return 0;
		}
		if(last == pivot)
		{
			printf("0\n");
			return 0;
		}
		start = maxEnd + 1;
	}
	printf("0\n");

	return 0;
}








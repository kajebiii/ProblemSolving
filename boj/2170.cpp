// =====================================================================================
//
//       Filename:  2170.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 01:29:01
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

const int MAX_N = 1e6 + 100;
const int INF = 0x7fffffff;

struct LINE 
{
	int x, y;
	const bool operator<(const LINE &other) const
	{
		return x < other.x;
	}
}L[MAX_N];

int N;

int main()
{
	scanf("%d", &N);

	for(int i=0; i<N; i++)
		scanf("%d%d", &L[i].x, &L[i].y);
	
	sort(L, L+N);

	int i = 0, result = 0;
	while(i < N)
	{
		int start = L[i].x, end = L[i].y;
		while(L[i+1].x <= end && i+1 < N) end = max(end, L[++i].y);
		result += (end - start);
		i++;
	}

	printf("%d\n", result);

	return 0;
}















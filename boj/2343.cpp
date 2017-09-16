// =====================================================================================
//
//       Filename:  2343.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/12/2016 19:51:59
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

int N, K;
int Nr[MAX_N];

int main()
{
	scanf("%d%d", &N, &K);
	
	int s = 0, e = 0x3fffffff, m;
	
	for(int i=0; i<N; i++)
	{
		scanf("%d", &Nr[i]);
		s = max(s, Nr[i]);
	}
	int result = 0;

	while(s <= e)
	{
		m = (s + e) / 2;
		int cnt = 0, sum = 0, now = 0;
		while(now != N)
		{
			while(sum + Nr[now] <= m && now != N) sum += Nr[now], now++;
			sum = 0;
			cnt++;
		}

		if(cnt <= K)
		{
			result = m;
			e = m - 1;
		}
		else
			s = m + 1;
	}

	printf("%d", result);

	return 0;
}

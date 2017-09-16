// =====================================================================================
//
//       Filename:  2515.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/12/2016 22:34:09
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

const int MAX_N = 3e5 + 30;

struct PIC
{
	int h, c;
	const bool operator<(const PIC &other) const
	{
		return h < other.h;
	}
}P[MAX_N];

int N, S;
int Dy[MAX_N];

int main()
{
	scanf("%d%d", &N, &S);
	for(int i=0; i<N; i++)
		scanf("%d%d", &P[i].h, &P[i].c);
	sort(P, P+N);

	int pivot = 0, nowMax = 0;
	int result = 0;
	for(int i=0; i<N; i++)
	{
		while(P[pivot].h + S <= P[i].h && pivot < N)
			nowMax = max(nowMax, Dy[pivot++]);
		Dy[i] = nowMax + P[i].c;
		result = max(result, Dy[i]);
	}

	printf("%d\n", result);

	return 0;
}










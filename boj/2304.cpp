// =====================================================================================
//
//       Filename:  2304.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/12/2016 19:44:29
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

int N;
int Nr[1111];
int Max[2][1111];

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		Nr[x] = y;
	}
	for(int i=1; i<=1011; i++)
		Max[0][i] = max(Max[0][i-1], Nr[i]);
	for(int i=1010; i>=0; i--)
		Max[1][i] = max(Max[1][i+1], Nr[i]);

	int result = 0;
	for(int i=1; i<=1010; i++)
		result += min(Max[0][i], Max[1][i]);

	printf("%d\n", result);
	return 0;
}

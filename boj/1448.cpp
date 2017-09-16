// =====================================================================================
//
//       Filename:  1448.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/15/2016 18:53:28
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

const int MAX_N = 1e6 + 10;

int N;
int Nr[MAX_N];

int main()
{
	scanf("%d", &N);

	for(int i=0; i<N; i++)
		scanf("%d", &Nr[i]);

	sort(Nr, Nr+N);

	int result = -1;
	for(int i=2; i<N; i++)
		if(Nr[i-1] + Nr[i-2] > Nr[i])
			result = Nr[i] + Nr[i-1] + Nr[i-2];

	printf("%d\n", result);

	return 0;
}

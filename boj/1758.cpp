// =====================================================================================
//
//       Filename:  1758.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/12/2016 14:23:55
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

const int MAX_N = 1e5 + 10;

int N;
int Nr[MAX_N];

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &Nr[i]);

	sort(Nr, Nr+N, greater<int>());

	long long result = 0;
	for(int i=0; i<N; i++)
		result += 1ll * max(0, Nr[i] - i);
	
	printf("%lld", result);

	return 0;
}

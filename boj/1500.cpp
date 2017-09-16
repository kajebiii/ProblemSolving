// =====================================================================================
//
//       Filename:  1500.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 19:05:33
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <iostream>

using namespace std;

long long Ans = 1;

int main()
{
	int S, K; cin >> S >> K;

	for(int i=0; i<K - (S%K); i++)
		Ans *= 1ll * S/K;
	for(int i=0; i < S%K; i++)
		Ans *= 1ll * (S/K + 1);

	printf("%lld\n", Ans);

	return 0;
}

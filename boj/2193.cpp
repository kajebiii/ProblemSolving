// =====================================================================================
//
//       Filename:  2193.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 20:52:12
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

using namespace std;

int main() {
	long long a = 1, aa = 1, aaa = -1;
	int N; cin >> N;
	for(int i=3; i<=N; i++)
	{
		aaa = a + aa;
		a = aa; aa = aaa;
	}
	if(aaa == -1)
		printf("1\n");
	else
		printf("%lld\n", aaa);
	return 0;
}











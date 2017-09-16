// =====================================================================================
//
//       Filename:  5543.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 21:44:04
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
	int a = 0x7fffffff, aa = 0x7fffffff;
	for(int i=0; i<3; i++)
	{
		int x; cin >> x;
		a = min(a, x);
	}
	for(int i=0; i<2; i++)
	{
		int x; cin >> x;
		aa = min(aa, x);
	}
	printf("%d\n", a + aa - 50);
	return 0;
}











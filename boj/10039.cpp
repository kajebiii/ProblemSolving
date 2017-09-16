// =====================================================================================
//
//       Filename:  10039.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 20:49:44
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
	int sum = 0;
	for(int i=0; i<5; i++)
	{
		int x; cin >> x;
		if(x < 40) x = 40;
		sum += x;
	}
	printf("%d\n", sum/5);
	return 0;
}











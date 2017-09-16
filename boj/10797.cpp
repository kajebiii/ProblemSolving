// =====================================================================================
//
//       Filename:  10797.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 21:11:14
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
	int k; cin >> k;
	int cnt = 0;
	for(int i=0; i<5; i++)
	{
		int x; cin >> x;
		if(k == x)
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}











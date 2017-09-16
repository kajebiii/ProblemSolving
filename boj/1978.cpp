// =====================================================================================
//
//       Filename:  1978.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 20:57:58
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
	int N; cin >> N;
	int cnt = 0;
	for(; N--; )
	{
		int x; cin >> x;
		if(x == 1) continue;
		bool flag = true;
		for(int i=2; i*i<=x; i++)
			if(x % i == 0)
				flag = false;
		if(flag) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}











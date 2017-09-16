// =====================================================================================
//
//       Filename:  1075.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 21:30:32
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
#include <queue>
#include <map>
#include <set>
#include <vector>

#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

int main() {
	int N, F; cin >> N >> F;
	for(int i=0; i<100; i++)
	{
		if( ((N/100) * 100 + i) % F == 0  )
		{
			printf("%02d\n", i);
			break;
		}
	}
	return 0;
}











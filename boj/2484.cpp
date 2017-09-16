// =====================================================================================
//
//       Filename:  2476.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 17:33:41
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
	int N; cin >> N;
	int result = 0;
	for(; N--; )
	{
		int A[4]; for(int i=0; i<4; i++) cin >> A[i];
		sort(A, A+4);
		int now = 0;
		if(A[0] == A[3])
			now = 50000 + A[0] * 5000;
		else if(A[0] == A[2])
			now = 10000 + A[0] * 1000;
		else if(A[1] == A[3])
			now = 10000 + A[1] * 1000;
		else if((A[0] == A[1] && A[2] != A[3]) || A[1] == A[2])
			now = 1000 + A[1] * 100;
		else if(A[0] == A[1] && A[2] == A[3])
			now = 2000 + (A[0] + A[2]) * 500;
		else if(A[2] == A[3])
			now = 1000 + A[2] * 100;
		else
			now = A[3] * 100;
		result = max(result, now);
	}
	cout << result;
	return 0;
}











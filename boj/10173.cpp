// =====================================================================================
//
//       Filename:  10173.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 16:38:13
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
#include <stack>
#include <math.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int main() {
	char A[88];
	while(1)
	{
		fgets(A, 88, stdin);
		if(A[0] == 'E' && A[1] == 'O' && A[2] == 'I') break;
		for(int i=0; A[i]; i++)
			if(A[i] >= 'A' && A[i] <= 'Z') A[i] += 'a' - 'A';
		bool find = false;
		for(int i=3; A[i]; i++)
			if(A[i-3] == 'n' && A[i-2] == 'e' && A[i-1] == 'm' && A[i] == 'o')
				find = true;
		if(find) puts("Found");
		else puts("Missing");
	}
	return 0;
}











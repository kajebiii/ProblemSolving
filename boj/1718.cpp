// =====================================================================================
//
//       Filename:  1718.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 14:55:52
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

char A[33333], B[33333];
int main() {
	fgets(A, 33333, stdin);
	fgets(B, 33333, stdin);
	int N = (int)strlen(B); if(B[N-1] < 'a') N--;
	int j = 0;
	for(int i=0; A[i]; i++)
	{
		if(A[i] < 'a') {printf("%c", A[i]); j = (j+1) % N;continue;}
		A[i] = ((A[i] - B[j] - 1 + 52) % 26 + 'a');
		printf("%c", A[i]);
		j = (j+1) % N;
	}
	return 0;
}











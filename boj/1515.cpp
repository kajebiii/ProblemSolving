// =====================================================================================
//
//       Filename:  1515.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 16:05:54
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


int N, AN;
char A[999999], S[3333];

void Plus(int v)
{
	if(v == 0) return;
	Plus(v/10);
	A[AN++] = v%10 + '0';
}

int main() {
	scanf("%s", S); N = (int)strlen(S);

	int ix=0, j=0;
	for(int i=1; i<=30000; i++)
	{
		Plus(i);
		while(ix<AN && j<N) if(A[ix]==S[j]) ix++, j++; else ix++;
		if(j == N)
		{
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}











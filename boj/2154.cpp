// =====================================================================================
//
//       Filename:  2154.cpp
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

int F[10], N, AN;
char S[10];
char A[999999];

void Plus(int v)
{
	if(v == 0) return;
	Plus(v/10);
	A[AN++] = v%10 + '0';
}

int main() {
	scanf("%s", S); N = (int)strlen(S);
	F[0] = -1; for(int i=0, j=-1; i<N; j<0||S[i]==S[j]?F[++i]=++j:j=F[j]);
	for(int i=1; i<=100000; i++) Plus(i);
	for(int i=0, j=0; i<AN;)
	{
		if(j<0 || A[i] == S[j])
		{
			i++;
			j++;
			if(j == N)
			{
				printf("%d", i-j+1);
				break;
			}
		}
		else
			j = F[j];
	}
	return 0;
}











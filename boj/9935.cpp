// =====================================================================================
//
//       Filename:  9935.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 13:23:31
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
const int MAX_N = 1e6 + 1000;

int F[99];
int Memo[MAX_N], Back[MAX_N];
int main() {
	string A, B; cin >> A >> B;
	int i, j;
	for(i=0, j=F[0]=-1; i<B.length(); j<0||B[i]==B[j]?F[++i]=++j:j=F[j]);
	for(i=0; i<=A.length(); i++) Back[i] = i-1;
	for(i=0, j=0; i<A.length(); )
	{
		if(j<0 || A[i] == B[j])
		{
			Memo[++i]=++j;
			if(j == B.length())
			{
				int now = i-1;
				for(int k=0; k<(int)B.length(); k++)
				{
					A[now] = ' ';
					now = Back[now];
				}
				Back[i] = now;
				j = Memo[now+1];
			}
		}
		else
			j = F[j];
	}
	
	bool isPrint = false;
	for(int i=0; i<A.length(); i++)
		if(A[i] != ' ') {printf("%c", A[i]); isPrint = true;}
	if(isPrint == false)
		printf("FRULA");

	return 0;
}











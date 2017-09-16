// =====================================================================================
//
//       Filename:  2684.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/05/2016 10:46:26
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

int C[999], Cnt[8];
char A[44];
int main() {
	int T; scanf("%d\n", &T); C['T'] = 0, C['H'] = 1;
	while(T--)
	{
		scanf("%s", A);
		for(int i=0; i<38; i++)
		{
			int now = 0;
			for(int k=0; k<3; k++)
				now *= 2, now += C[A[i+k]];
			Cnt[now]++;
		}
		for(int i=0; i<8; i++) printf("%d ", Cnt[i]), Cnt[i] = 0; printf("\n");
	}
	return 0;
}











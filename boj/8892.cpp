// =====================================================================================
//
//       Filename:  8892.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 15:59:59
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

int N;
char S[111][11111], Ans[11111], C[11111];

int main() {
	int T; cin >> T;
	while(T--)
	{
		cin >> N; for(int i=0; i<N; i++) scanf("%s", S[i]);

		bool find = false;
		for(int i=0; i<11111; i++) Ans[i] = 0;
		for(int i=0; i<N; i++) for(int j=0; j<N; j++)
			if(i != j)
			{
				if(find) break;
				int cnt = 0;
				for(int k=0; S[i][k]; k++) C[cnt++] = S[i][k];
				for(int k=0; S[j][k]; k++) C[cnt++] = S[j][k];

				bool isPal = true;
				for(int k=0; k<cnt; k++)
					if(C[cnt-1-k] != C[k]) isPal = false;
				if(isPal)
				{
					find = true;
					for(int k=0; k<cnt; k++) Ans[k] = C[k]; Ans[cnt] = 0;
				}
			}
		if(find) printf("%s\n", Ans);
		else printf("0\n");
	}
	return 0;
}











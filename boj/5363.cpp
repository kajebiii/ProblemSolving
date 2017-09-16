// =====================================================================================
//
//       Filename:  5363.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 20:28:41
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
	int N; scanf("%d\n", &N);
	while(N--)
	{
		char C[111]; fgets(C, 111, stdin);
		int K = (int)strlen(C) - 1; C[K] = 0;
		int cnt = 0;
		for(int i=0; i<K; i++)
		{
			if(C[i] == ' ') cnt++;
			if(cnt == 2)
			{
				printf("%s ", C+i+1);
				for(int j=0; j<i; j++) printf("%c", C[j]);
				printf("\n");
				break;
			}
		}
	}
	return 0;
}











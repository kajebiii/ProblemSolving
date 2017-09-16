// =====================================================================================
//
//       Filename:  2798.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 02:29:12
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

int N, M, Nr[111];
int main() {
	cin >> N >> M; for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	int Ans = 0;
	for(int i=0; i<N; i++) for(int j=i+1; j<N; j++) for(int k=j+1; k<N; k++)
		if(Nr[i]+Nr[j]+Nr[k] <= M) 
			Ans = max(Ans, Nr[i]+Nr[j]+Nr[k]);
	cout << Ans;
	return 0;
}











// =====================================================================================
//
//       Filename:  1731.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 15:09:18
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

int N, Nr[55];
int main() {
	cin >> N; for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	if(Nr[0]+Nr[2] == Nr[1]*2)
		printf("%d", Nr[N-1] + Nr[1] - Nr[0]);
	else
		printf("%d", Nr[1]/Nr[0]*Nr[N-1]);
	return 0;
}











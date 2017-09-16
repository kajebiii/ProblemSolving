// =====================================================================================
//
//       Filename:  11576.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 23:39:57
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

int B;
void printAns(int n)
{
	if(n==0) return;
	printAns(n/B);
	printf("%d ", n%B);
}

int main() {
	int A; cin >> A >> B;
	int M; cin >> M;
	int P = 1; for(int i=1; i<M; i++) P *= A;
	int ans = 0;
	for(int i=M-1; i>=0; i--)
	{
		int x; scanf("%d", &x);
		ans += x * P;
		P /= A;
	}
	printAns(ans);
	return 0;
}











// =====================================================================================
//
//       Filename:  10825.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 17:34:35
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
const int MAX_N = 101101;

struct DATA
{
	string name;
	int a, b, c;
	const bool operator<(const DATA &o) const
	{
		return a!=o.a?a>o.a:b!=o.b?b<o.b:c!=o.c?c>o.c:name<o.name;
	}
}D[MAX_N];
char A[20];

int main() {
	int N; cin >> N; scanf("\n");
	for(int i=0; i<N; i++)
	{
		scanf("%s", A+1); D[i].name = string(A+1);
		scanf("%d%d%d", &D[i].a, &D[i].b, &D[i].c);
	}
	sort(D, D+N);
	for(int i=0; i<N; i++) 
	{
		const char *output = D[i].name.c_str();
		printf("%s\n", output);
	}
	return 0;
}











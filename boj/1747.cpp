// =====================================================================================
//
//       Filename:  1747.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 19:59:27
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

bool notP[2000001];
bool isOK(int v)
{
	if(notP[v] == true) return false;
	int temp = v, rv = v%10;
	while(temp/=10) rv *= 10, rv += temp%10;
	return rv == v;
}
int main() {
	int N; cin >> N;
	notP[1] = true;
	for(int i=2; i<=2000000; i++)
		if(notP[i] == false)
			for(int j=i*2; j<=2000000; j+=i)
				notP[j] = true;
	for(int i=N; ; i++)
		if(isOK(i)) {printf("%d\n", i); break;}
	return 0;
}











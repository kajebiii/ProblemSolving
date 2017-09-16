// =====================================================================================
//
//       Filename:  9733.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/02/2016 22:06:40
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

string S[7] = {"Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex"};
map<string, int> M;

int main() {	
	string K; 
	for(int i=0; i<7; i++) M[S[i]] = 0;
	int all = 0;
	while(cin >> K) M[K]++, all++;
	for(int i=0; i<7; i++)
	{
		cout << S[i]; printf(" %d %.2lf\n", M[S[i]], M[S[i]]*1.0/all);
	}
	printf("Total %d 1.00\n", all);
	return 0;
}











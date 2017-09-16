// =====================================================================================
//
//       Filename:  2608.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/10/2016 22:34:39
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
#ifndef ONLINE_JUDGE
const bool debug = true;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

map<char, int> M;
int get()
{
	string S; cin >> S;
	int result = 0;
	for(int i=0; i<S.length(); i++)
		if(i+1 < S.length() && M[S[i]] < M[S[i+1]])
			result -= M[S[i]];
		else
			result += M[S[i]];
	return result;
}
char ToRome[4][3];
void Rome(int n, int p)
{
	if(n == 0) return;
	Rome(n/10, p+1);
	if(n % 10 == 9) {printf("%c%c", ToRome[p][0], ToRome[p][2]); return;}
	if(n % 10 == 4) {printf("%c%c", ToRome[p][0], ToRome[p][1]); return;}
	if(n % 10 >= 5) {printf("%c", ToRome[p][1]); n -= 5;}
	for(int i=0; i<n%10; i++)
		printf("%c", ToRome[p][0]);
}
int main() {
	M['I'] = 1; M['V'] = 5; M['X'] = 10; M['L'] = 50;
	M['C'] = 100; M['D'] = 500; M['M'] = 1000;
	int Ans = get() + get();
	printf("%d\n", Ans);
	ToRome[0][0] = 'I'; ToRome[0][1] = 'V'; ToRome[0][2] = 'X';
	ToRome[1][0] = 'X'; ToRome[1][1] = 'L'; ToRome[1][2] = 'C';
	ToRome[2][0] = 'C'; ToRome[2][1] = 'D'; ToRome[2][2] = 'M';
	ToRome[3][0] = 'M';
	Rome(Ans, 0);
	return 0;
}











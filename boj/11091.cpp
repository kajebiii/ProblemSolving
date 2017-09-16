// =====================================================================================
//
//       Filename:  11091.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 19:36:27
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
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

string S;
int Chk[27];
int main() {
	int N; scanf("%d\n", &N);
	while(N--)
	{
		getline(cin, S);
		for(int i=0; i<26; i++) Chk[i] = 0;
		for(char &x : S) if(x >= 'A' && x <= 'Z') x = x + ('a' - 'A');
		for(char x : S) if(x >= 'a' && x <= 'z') Chk[x - 'a'] = 1;
		int cnt = 0; for(int i=0; i<26; i++) cnt += Chk[i];
		if(cnt == 26) puts("pangram");
		else
		{
			printf("missing ");
			for(int i=0; i<26; i++) if(Chk[i] == 0) printf("%c", i+'a');
			puts("");
		}
	}
	return 0;
}











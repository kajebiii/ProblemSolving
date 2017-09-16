// =====================================================================================
//
//       Filename:  1406.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 00:44:25
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

struct LIST
{
	LIST *l, *r;
	char k;
}*first;

char S[111111];
int main() {
	first = new LIST(); first -> l = first -> r = NULL;
	scanf("%s", S);
	LIST *now = first;
	for(int i=0; S[i]; i++)
	{
		now -> r = new LIST();
		now -> r -> r = NULL;
		now -> r -> l = now;
		now -> r -> k = S[i];
		now = now -> r;
	}
	int N; scanf("%d\n", &N);
	while(N--)
	{
		char t; scanf("%c", &t);
		if(t == 'L')
			now = now -> l != NULL ? now -> l : now;
		if(t == 'D')
			now = now -> r != NULL ? now -> r : now;
		if(t == 'B' && now -> l != NULL)
		{
			now -> l -> r = now -> r;
			if(now -> r != NULL)
				now -> r -> l = now -> l;
			LIST *past = now;
			now = now -> l;
			delete past;
		}
		if(t == 'P')
		{
			char x; scanf(" %c\n", &x);
			LIST *plus = new LIST();
			plus -> l = now;
			plus -> r = now -> r;
			if(now -> r != NULL) now -> r -> l = plus;
			plus -> k = x;
			now -> r = plus;
			now = plus;
		}
		else
			scanf("\n");
	}
	for(now = first -> r; now != NULL; now = now -> r)
		printf("%c", now -> k);
	return 0;
}











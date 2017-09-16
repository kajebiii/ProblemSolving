// =====================================================================================
//
//       Filename:  5397.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 01:32:20
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
	char x;
}*first;
char S[1001001];
int main() {
	int T; scanf("%d\n", &T);
	while(T--)
	{
		first = new LIST(); first -> l = first -> r = NULL;
		scanf("%s", S);
		LIST *now = first;
		for(int i=0; S[i]; i++)
		{
			if(S[i] == '<' && now -> l != NULL)
				now = now -> l;
			if(S[i] == '>' && now -> r != NULL)
				now = now -> r;
			if(S[i] == '-' && now -> l != NULL)
			{
				now -> l -> r = now -> r;
				if(now -> r != NULL)
					now -> r -> l = now -> l;
				LIST *past = now;
				now = now -> l;
				delete past;
			}
			if(S[i] != '<' && S[i] != '>' && S[i] != '-')
			{
				LIST *node = new LIST();
				node -> l = now;
				node -> r = now -> r;
				node -> x = S[i];
				if(now -> r != NULL)
					now -> r -> l = node;
				now -> r = node;
				now = node;
			}
		}
		for(now = first -> r; now != NULL;)
		{
			printf("%c", now -> x);
			LIST *past = now;
			now = now -> r;
			delete past;
		}
		printf("\n");
		delete first;
	}
	return 0;
}











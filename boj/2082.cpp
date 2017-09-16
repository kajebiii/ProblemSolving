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
pi operator +(const pi &x, const pi &y) { return mp(x.fi+y.fi, x.se+y.se); }

const int INF = 0x7fffffff;
const pi Ch[4] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1) };

char A[4][5][5];
char Nr[10][5][4] = 
{
	
	{
	 "###"
	,"#.#"
	,"#.#" 
	,"#.#" 
	,"###"
	},
	{
	 "..#"
	,"..#"
	,"..#" 
	,"..#" 
	,"..#"
	},
	{
	 "###"
	,"..#"
	,"###" 
	,"#.." 
	,"###"
	},
	{
	 "###"
	,"..#"
	,"###" 
	,"..#" 
	,"###"
	},
	{
	 "#.#"
	,"#.#"
	,"###" 
	,"..#" 
	,"..#"
	},
	{
	 "###"
	,"#.."
	,"###" 
	,"..#" 
	,"###"
	},
	{
	 "###"
	,"#.."
	,"###" 
	,"#.#" 
	,"###"
	},
	{
	 "###"
	,"..#"
	,"..#" 
	,"..#" 
	,"..#"
	},
	{
	 "###"
	,"#.#"
	,"###" 
	,"#.#" 
	,"###"
	},
	{
	 "###"
	,"#.#"
	,"###" 
	,"..#" 
	,"###"
	},
};
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	for(int j=0; j<5; j++) for(int i=0; i<4; i++) scanf("%s", A[i][j]);
	for(int h=0; h<24; h++) for(int m=0; m<60; m++)
	{
		int now[4] ={ h/10, h%10, m/10, m%10 };
		bool isCan = true;
		for(int k=0; k<4; k++)
		{
			bool nowCan = true;
			for(int i=0; i<5; i++) for(int j=0; j<3; j++)
				if(A[k][i][j] == '#' && Nr[now[k]][i][j] == '.') nowCan = false;
			if(nowCan == false) isCan = false;
		}
		if(isCan)
		{
			printf("%02d:%02d\n", h, m);
			return 0;
		}
	}
	return 0;
}
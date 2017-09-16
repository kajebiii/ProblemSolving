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
const int MAX_N = 1e6 + 1000;

int Go[2][10] =
{
	{6, 2, 3, 3, 6, 9, 8, 6, 8, 3},
	{1, 8, 8, 4, 5, 5, 7, 1, 8, 7}
};
char S[222];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	while(fgets(S, 222, stdin))
	{
		int N = strlen(S);
		if(S[N-1] == '\n') N--;
		int now = 0;
		for(int i=0; i<N; i++)
			now = Go[S[i] - '0'][now];
		if(now != 7 && now != 4 && now != 5) puts("NOISE");
		else puts("SUBMARINE");
	}
	return 0;
}
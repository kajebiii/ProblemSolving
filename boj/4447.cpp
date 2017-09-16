#include <stdio.h>
#include <functional>
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

char S[99];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	
	int TC; scanf("%d\n", &TC);

	while(TC--)
	{
		fgets(S, 99, stdin);
		int g = 0, b = 0;
		for(int i=0; S[i] != 0; i++)
		{
			if(S[i] == 'G' || S[i] == 'g') g++;
			if(S[i] == 'B' || S[i] == 'b') b++;
		}
		int N = strlen(S);
		if(S[N-1] == '\n') S[N-1] = 0;
		printf("%s is ", S);
		if(g > b) puts("GOOD");
		else if(g == b) puts("NEUTRAL");
		else puts("A BADDY");
	}
	return 0;
}
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

const int MAX_N = 1111;

int N;
char Nr[MAX_N], MinNr[MAX_N];
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	int TC; cin >> TC;

	MinNr[0] = 'Z';
	while(TC--)
	{
		scanf("%d\n", &N);
		for(int i=1; i<=N; i++) scanf("%c ", &Nr[i]);
		for(int i=1; i<=N; i++) MinNr[i] = min(MinNr[i-1], Nr[i]);
		stack<char> S;
		for(int i=N; i>=1; i--)
			if(MinNr[i] == Nr[i])
				printf("%c", Nr[i]);
			else
				S.push(Nr[i]);
		while(!S.empty())
		{
			printf("%c", S.top());
			S.pop();
		}
		puts("");
	}

	return 0;
}
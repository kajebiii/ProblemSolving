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

queue<int> Q[1111];
int MatchF[1111], F[1111][1111], M[1111][1111];
int Ans[1111], N;
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++)
	{
		int x; scanf("%d", &x);
		Q[i].push(x-1);
	}
	for(int i=0; i<N; i++) for(int j=0, x; j<N; j++)
		scanf("%d", &x), F[i][x-1] = N-j;
	for(int i=0; i<N; i++) MatchF[i] = -1;

	queue<int> unMatch;
	for(int i=0; i<N; i++) unMatch.push(i);
	while(!unMatch.empty())
	{
		int man = unMatch.front(); unMatch.pop();
		while(!Q[man].empty())
		{
			int w = Q[man].front(); Q[man].pop();
			if(MatchF[w] == -1 || F[w][MatchF[w]] < F[w][man])
			{
				if(MatchF[w] != -1) unMatch.push(MatchF[w]);
				MatchF[w] = man;
				break;
			}
		}
	}

	for(int i=0; i<N; i++) Ans[MatchF[i]] = i+1;
	for(int i=0; i<N; i++) printf("%d\n", Ans[i]);
	return 0;
}
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
const int MAX_N = 111;

int N, T, Dy[MAX_N][22];
vector<int> V[MAX_N];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N >> T;
	for(int i=1; i<=N; i++)
	{
		int k; scanf("%d", &k);
		for(int j=0; j<k; j++)
		{
			int x; scanf("%d", &x);
			V[i].pb(x);
		}
	}
	for(int j=0; j<=N; j++) for(int i=0; i<=21; i++) Dy[j][i] = INF; 
	Dy[0][1] = 0; V[0].pb(1);

	for(int k=1; k<=N; k++)
	{

		int T = INF; for(int i=1; i<=20; i++) T = min(T, Dy[k-1][i]);
		for(int i : V[k])
		{
			for(int l=-1; l<=1; l++) Dy[k][i] = min(Dy[k][i], Dy[k-1][i+l]);
			if(i % 2 == 0) Dy[k][i] = min(Dy[k][i], Dy[k-1][i/2]);
			if(i == 20) for(int l=10; l<=20; l++) Dy[k][i] = min(Dy[k][i], Dy[k-1][l]);
			if(Dy[k][i] == INF) Dy[k][i] = T + 1;
			if(debug) printf("%d %d : %d\n", k, i, Dy[k][i]);
		}
	}
	
	int minT = INF;
	for(int i : V[N]) minT = min(Dy[N][i], minT);
	if(minT > T) puts("-1");
	else printf("%d", minT);
	return 0;
}
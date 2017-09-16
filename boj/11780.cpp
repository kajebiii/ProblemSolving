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

const int MAX_N = 1e2 + 10;

int Dis[MAX_N][MAX_N];
int P[MAX_N][MAX_N];
int N, M;

vector<int> getAns(int x, int y)
{
	if(P[x][y] == -1) return vector<int>(0, 0);
	if(P[x][y] == x) return vector<int>({ x, y });
	vector<int> A = getAns(x, P[x][y]);
	vector<int> B = getAns(P[x][y], y);
	vector<int> Result = A;
	Result.pop_back();
	for(int x : B) Result.pb(x);
	return Result;
}
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(i!=j) Dis[i][j] = INF/3;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		P[i][j] = -1;
	for(int i=1; i<=M; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		Dis[a][b] = min(Dis[a][b], c);
		P[a][b] = a;
	}

	for(int k=1; k<=N; k++) for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(Dis[i][j] > Dis[i][k] + Dis[k][j])
		{
			Dis[i][j] = Dis[i][k] + Dis[k][j];
			P[i][j] = k;
		}

	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(Dis[i][j] == INF/3) Dis[i][j] = 0;
	for(int i=1; i<=N; i++, puts("")) for(int j=1; j<=N; j++)
		printf("%d ", Dis[i][j]);
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
	{
		vector<int> V = getAns(i, j);
		printf("%d", (int)V.size());
		for(int x : V) printf(" %d", x); puts("");
	}
	return 0;
}
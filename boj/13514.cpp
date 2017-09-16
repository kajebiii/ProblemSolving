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
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const int MAX_N = 1e5 + 100, LOG_N = 20;

int N; vector<int> V[MAX_N], Visit, Centers[MAX_N];
int S[MAX_N], D[MAX_N], P[MAX_N][LOG_N+1], C[MAX_N], Color[MAX_N]; // 1 : White
multiset<int> Sets[MAX_N];

void initDFS(int v, int p, int ifC)
{
	Visit.push_back(v);
	S[v] = 1; D[v] = D[p] + 1; P[v][0] = p; 
	if(ifC == 1) for(int i=1; i<=LOG_N; i++) 
		P[v][i] = P[P[v][i-1]][i-1];
	for(int w : V[v])
		if(w != p && C[w] == ifC)
			initDFS(w, v, ifC), S[v] += S[w];
}
void getCenterWith(int v)
{
	Visit.clear();
	initDFS(v, 0, 0);
	int center = v, nowN = S[v];
	for(int x : Visit) if(S[x] * 2 >= nowN && S[center] > S[x]) center = x;
	for(int x : Visit) Centers[x].push_back(center);
	C[center] = 1; Sets[center].insert(INF/2);
	for(int w : V[center]) if(C[w] != 1) getCenterWith(w);
}
int getDis(int a, int b)
{
	int result = 0;
	if(D[a] > D[b]) swap(a, b);
	for(int i=0; i<=LOG_N; i++) if((1<<i) & (D[b] - D[a])) b = P[b][i], result += (1<<i);
	if(a == b) return result;
	for(int i=LOG_N; i>=0; i--) if(P[a][i] != P[b][i])
		a = P[a][i], b = P[b][i], result += (1<<i) * 2;
	return result + 2;
}
void update(int v)
{
	Color[v] ^= 1;
	for(int root : Centers[v]) 
		if(Color[v] == 1)
			Sets[root].insert(getDis(root, v));
		else
			Sets[root].erase(Sets[root].find(getDis(root, v)));
}
int query(int v)
{
	int result = INF / 2;
	for(int root : Centers[v])
		result = min(result, getDis(v, root) + *Sets[root].begin());
	if(result == INF / 2) return -1;
	return result;
}
int main()
{
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N; 
	for(int i=1, x, y; i<N; i++) 
		scanf("%d%d", &x, &y),
		V[x].push_back(y), V[y].push_back(x);
	getCenterWith(1);
	initDFS(1, 0, 1);
//  for(int i=1; i<=N; i++, puts("")) for(int x : Centers[i]) printf("[%d : %d] ", i, x);
	int Q; cin >> Q;
	for(int i=1; i<=Q; i++)
	{
		int t, x; scanf("%d%d", &t, &x);
		if(t == 1) update(x);
		else printf("%d\n", query(x));
	}

	return 0;
}
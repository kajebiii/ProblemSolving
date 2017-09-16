// =====================================================================================
//
//       Filename:  13513.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  11/17/2016 21:52:18
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

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
#include <assert.h>

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

const int INF = 0x7fffffff, MAX_N = 1e5 + 100, LOG_N = 20;

int T[MAX_N * 4], TN, Co[MAX_N];
void update(int v, int k) { T[v] = k; while(v/=2) T[v] = max(T[v*2], T[v*2+1]); }
int N; vector<pi> V[MAX_N];
int ChkC[MAX_N], S[MAX_N], Pa[MAX_N][LOG_N+1], W[MAX_N][LOG_N+1], D[MAX_N];
vector<int> List;
vector<pi> P[MAX_N]; int From[MAX_N];
void initDFS(int v, int p, int l)
{
	if(l == 0) List.pb(v);
	Pa[v][0] = p; D[v] = D[p] + 1;
	for(int i=1; i<=LOG_N; i++) 
		Pa[v][i] = Pa[Pa[v][i-1]][i-1], W[v][i] = W[Pa[v][i-1]][i-1] + W[v][i-1];
	S[v] = 1;
	for(pi &temp : V[v])
	{
		int w = temp.fi;
		if(ChkC[w] == 1) continue;
		if(w == p) continue;
		W[w][0] = temp.second;
		initDFS(w, v, l);
		S[v] += S[w];
	}
}
void fromDFS(int v, int p, int from)
{
	From[v] = from;
	for(pi &temp : V[v])
	{
		int w = temp.first;
		if(ChkC[w] == 1) continue;
		if(w == p) continue;
		fromDFS(w, v, from);
	}
}

vector<multiset<int>> Sets[MAX_N];
multiset<pi> Maxs[MAX_N];
void findCenter(int one)
{
	List.clear();
	initDFS(one, 0, 0);
	int all = S[one], cent = one;
	for(int v : List) if(S[v] * 2 >= all && S[cent] > S[v]) cent = v;
	ChkC[cent] = 1;

	int cnt = 0;
	for(pi &temp : V[cent]) if(ChkC[temp.first] != 1) 
		fromDFS(temp.first, cent, cnt++), Sets[cent].push_back(multiset<int>({-1}));
	From[cent] = cnt++, Sets[cent].push_back(multiset<int>({-1}));
	for(int i=0; i<cnt+1; i++) Maxs[cent].insert(mp(-1, i));
	for(int v : List) P[v].push_back(mp(cent, From[v]));
	for(pi &temp : V[cent]) if(ChkC[temp.fi] == 0) findCenter(temp.fi);
}
int getDis(int a, int b)
{
	if(D[a] > D[b]) swap(a, b);
	int result = 0;
	for(int i=0; i<=LOG_N; i++) if((1<<i) & (D[b] - D[a])) 
		result += W[b][i], b = Pa[b][i];
	if(a == b) return result;
	for(int i=LOG_N; i>=0; i--) if(Pa[b][i] != Pa[a][i])
		result += W[a][i] + W[b][i],
		a = Pa[a][i], b = Pa[b][i];
	result += W[a][0] + W[b][0];
	return result;
}

void upCenter(int v)
{
	for(pi &temp : P[v])
	{
		int root = temp.first, cnt = temp.second;
		multiset<int> &now = Sets[root][cnt];
		int dis = getDis(v, root);
		if(Co[v] == 0) 
		{
			int before = *now.rbegin();
			now.insert(dis);
			if(dis > before)
				Maxs[root].erase(mp(before, cnt)),
				Maxs[root].insert(mp(dis, cnt));
		}
		else 
		{
			int before = *now.rbegin();
			now.erase(now.find(dis));
			if(dis == before)
				Maxs[root].erase(mp(before, cnt)),
				Maxs[root].insert(mp(*now.rbegin(), cnt));
		}
		auto it = Maxs[root].rbegin();
		int max0 = it -> first; it++; int max1 = it -> first;
		int result = -1;
		if(max0 != -1)
		{
			if(max1 != -1) result = max0 + max1;
			else if(max0 == 0) result = 0;
		}
//		printf("upCent(%d) : %d -> %d (dis : %d | maxs %d and %d)\n", v, root, result, dis, max0, max1);
		update(TN + root - 1, result);
	}
}
int main()
{
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N; for(int x, y, c, i=1; i<N; i++)
		scanf("%d%d%d", &x, &y, &c), V[x].pb(mp(y, c)), V[y].pb(mp(x, c));
	findCenter(1);
	for(int i=1; i<=N; i++) ChkC[i] = 0;
	initDFS(1, 0, 1);
	for(TN=1; TN<N; TN<<=1);
	for(int i=1; i<2*TN; i++) T[i] = -1;
	for(int i=1; i<=N; i++) reverse(P[i].begin(), P[i].end());
//	for(int i=1; i<=N; i++, puts("")) for(pi &x : P[i]) printf("[%d %d]", x.first, x.se);

	for(int i=1; i<=N; i++) Co[i] = 1;
	for(int i=1; i<=N; i++)
	{
		Co[i] = 1 - Co[i];
		upCenter(i);
	}

	int Q; cin >> Q;
	for(int i=0; i<Q; i++)
	{
		int k; scanf("%d", &k);
		if(k == 1)
		{
			int x; scanf("%d", &x);
			Co[x] = 1 - Co[x];
			upCenter(x);
		}
		else printf("%d\n", T[1]);
	}
	return 0;
}











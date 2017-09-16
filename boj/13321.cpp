#include <stdio.h>
#include <algorithm>
#include<vector>
#include<stdlib.h>
#include<cassert>

using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)

const int MAXV = 505;
const int MAXE = MAXV * MAXV * 2;
const int LIM = 2e8;
int st[MAXV], en[MAXE], nxt[MAXE], flow[MAXE];
int cur[MAXV];
int N, M;

void addedge(int c,int s,int e,int f){
	nxt[c] = st[s], st[s] = c, en[c] = e, flow[c] = f;
}

int dis[MAXV], que[MAXV];
int start[MAXV];

long long cnt = 0;

int bfs(){
	for(int i=1;i<=N;i++)dis[i] = -1;
	dis[1] = 0;
	int *fr = que, *re = que;
	*fr++ = 1;
	while(fr != re){
		int t = *re++;
		for(int i=st[t];i!=-1;i=nxt[i]){
			
			cnt ++; /**/

			if(flow[i] > 0 && dis[en[i]] == -1){
				dis[en[i]] = dis[t] + 1;
				*fr++ = en[i];
			}
		}
	}
	return dis[N] != -1;
}

int dfs(int x, int f){
	if(x == N)return f;
	for(;cur[x]!=-1;cur[x]=nxt[cur[x]]){
		cnt ++; /**/
		int i = cur[x], temp;
		if(flow[i] > 0 && dis[en[i]] == dis[x] + 1 && (temp = dfs(en[i], min(f, flow[i]))) != -1){
			flow[i] -= temp;
			flow[i^1] += temp;
			return temp;
		}
	}
	return -1;
}

#define pb push_back
#define mt make_tuple
#include <tuple>

const int INF = 100000000;

bool chk[MAXV][MAXV];
vector<tuple<int, int, int>> V;
int solve(){
	N = 500;
	for(int i=1; i<=N-2; i++) V.pb(mt(i, i+1, INF));
	for(int i=1; i<=N-1; i++) V.pb(mt(i, N  , 1));
	for(int i=3; i<=N-1; i++) for(int j=1; j<=i-2; j++)
		V.pb(mt(i, j, INF));
	M = (int)V.size();
	assert( 2 <= N && N <= 502 && 0 <= M && M <= N * (N-1));

	for(int i=1;i<=N;i++)st[i] = -1;
	printf("%d %d\n", N, M);
	rep(i, M){
		int x, y, z;
		tie(x, y, z) = V[i];
		printf("%d %d %d\n", x, y, z);
		assert( 1 <= x && x <= N && 1 <= y && y <= N && x != y && 1 <= z && z <= 100000000);
		assert(!chk[x][y]);
		chk[x][y] = 1;
		addedge(i+i, x, y, z);
		addedge(i+i+1, y, x, 0);
	}
	return 0;
	int ans = 0;
	while(bfs()){
		for(int i = 1; i <= N; i++) cur[i] = st[i];
		while(1){
			int t = dfs(1, ~0u>>1);
			if(t == -1)break;
			ans += t;
			if( cnt >= LIM ) break;
		}
		if( cnt >= LIM ) break;
	}
	assert(cnt >= LIM);
	return ans;
}

int main()
{
	solve();
	return 0;
}

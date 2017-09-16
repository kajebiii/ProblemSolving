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
const int MAX_N = 1e5 + 100;

int N, K, P;
ll Tree[MAX_N * 4];
int Ch(int x)
{
	if(x == 0) return N+1;
	if(x > 0) return 0;
	return 1;
}
void U(int v, int k) { Tree[v] = k; while(v/=2) { Tree[v] = Tree[v*2] + Tree[v*2+1]; } }
ll G(int a, int b) { return a>b?0:G((a+1)/2, (b-1)/2) + (a%2==1?Tree[a]:0) + (b%2==0?Tree[b]:0); }
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	while(scanf("%d%d", &N, &K) == 2)
	{
		for(P=1; P<N; P<<=1);
		for(int i=1; i<2*P; i++) Tree[i] = 0;
		for(int i=0; i<N; i++)
		{
			int x; scanf("%d", &x);
			Tree[P+i] = Ch(x);
		}
		for(int i=P-1; i>=1; i--) Tree[i] = Tree[i*2] + Tree[i*2+1];

		for(int i=0; i<K; i++)
		{
			char c; scanf("%*[ \n]%c", &c);
			int x, y; scanf("%d%d", &x, &y);
			if(c == 'C') U(P+x-1, Ch(y));
			else
			{
				ll now = G(P+x-1, P+y-1);
				if(now > N) printf("0");
				else if(now % 2 == 0) printf("+");
				else printf("-");
			}
		}
		puts("");
	}
	return 0;
}
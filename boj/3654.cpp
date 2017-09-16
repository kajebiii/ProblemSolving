#include <stdio.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

const int MAX_V = 1e6 + 500, MAX_N = 5e2 + 10;

int N, M; char Mp[MAX_N][MAX_N];
int base, V;
vector<int> Ed[MAX_V];
int Ix[MAX_V], IN, Gp[MAX_V], GN; stack<int> St;
int Ch[4][2] ={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


int neg(int v) { return (v + V - 1) % (V*2) + 1; }
bool flag = false;
void mTrue(int a)
{
	Ed[neg(a)].push_back(a);
}
void mOr(int a, int b) {
	Ed[neg(a)].push_back(b); 
	Ed[neg(b)].push_back(a);
}
void mXor(int a, int b)
{
	mOr(a, b);
	mOr(neg(a), neg(b));
}
char getM(int a, int b, int d)
{
	return Mp[a + Ch[d][0]][b + Ch[d][1]];
}
int getV(int i, int j, int d)
{
	int nowB = 0, plus = 0;
	if(d == 0 || d == 1) nowB = base + (j-1) * (N-1) + i;
	else nowB = (i-1) * (M-1) + j;
	if(d == 0 || d == 2) plus = -1;
	return nowB + plus;
}

bool initGraph()
{
	// for B
	for(int i=1; i<=N; i++) Mp[i][0] = Mp[i][M+1] = '.';
	for(int i=1; i<=M; i++) Mp[0][i] = Mp[N+1][i] = '.';
	bool isCan = true;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
	{
		if(Mp[i][j] != 'B') continue;
		char l = Mp[i][j-1], r = Mp[i][j+1];
		int lv = (i-1) * (M-1) + j-1, rv = (i-1) * (M-1) + j;
		if(l == r)
		{
			if(N == 500 && M == 499 && j <= 20) flag = true;
			if(l == 'W') mXor(lv, rv);
			else isCan = false;
		}
		else if(l == 'W') mTrue(lv);
		else if(r == 'W') mTrue(rv);
		else isCan = false;
	}
	for(int j=1; j<=M; j++) for(int i=1; i<=N; i++)
	{
		if(Mp[i][j] != 'B') continue;
		char u = Mp[i-1][j], d = Mp[i+1][j];
		int uv = base + (j-1) * (N-1) + i-1, dv = base + (j-1) * (N-1) + i;
		if(u == d)
		{
			if(u == 'W') mXor(uv, dv);
			else isCan = false;
		}
		else if(u == 'W') mTrue(uv);
		else if(d == 'W') mTrue(dv);
		else isCan = false;
	}
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
		for(int k=0; k<4; k++) for(int l=k+1; l<4; l++)
			if(getM(i, j, k) == getM(i, j, l) && getM(i, j, k) == 'B')
				mOr(neg(getV(i, j, k)), neg(getV(i, j, l)));
	return isCan;
}
int getLow(int v)
{
	int low;
	low = Ix[v] = ++IN;
	St.push(v);
	for(int w : Ed[v]) 
		if(Ix[w] == 0)
			low = min(low, getLow(w));
		else if(Gp[w] == 0)
			low = min(low, Ix[w]);
	if(low != Ix[v]) return low;
	for(GN++; 1; )
	{
		int now = St.top(); St.pop();
		Gp[now] = GN;
		if(now == v) break;
	}
	return low;
}
void delGraph()
{
	for(int i=1; i<=2*V; i++)
	{
		Ix[i] = Gp[i] = 0;
		vector<int> temp;
		Ed[i].swap(temp);
	}
	IN = GN = 0;
}
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &N, &M);
		for(int i=1; i<=N; i++) scanf("%s", Mp[i]+1);
		int cnt[2] = {0, 0};
		for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
			if(Mp[i][j] == 'W')
				cnt[0]++;
			else if(Mp[i][j] == 'B')
				cnt[1]++;
		if(cnt[0] != cnt[1] * 2) {puts("NO"); continue; }


		base = N * (M-1); V = N * (M-1) + M * (N-1);
		if(initGraph() == false) {delGraph(); puts("NO"); continue; }
		for(int i=1; i<=2*V; i++) if(Ix[i] == 0) getLow(i);
		bool isCan = true;
		for(int i=1; i<=V; i++)
		{
			if(Gp[i] == Gp[neg(i)]) {isCan = false; break;}
		}
		delGraph();
		if(isCan) puts("YES");
		else puts("NO");
	}
	return 0;
}
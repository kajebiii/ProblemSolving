#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <string.h>
#include <string>

using namespace std;

const int MAX_N = 2e3 + 500, INF = 0x7fffffff;

int TN, N, Sum, Ball[MAX_N], Size[MAX_N];
char tree[MAX_N * 3];
vector<int> Ed[MAX_N];

void initGraph()
{
	TN = strlen(tree);
	stack<int> S; S.push(0);
	for(int i=0; i<TN; i++)
	{
		if(tree[i] == '(') S.push(++N);
		if(tree[i] == 'B') Ball[N]++;
		if(tree[i] == ')')
		{
			int now = S.top(); S.pop();
			if(Ed[now].size() == 0) Size[now]++;
			if(S.top() == 0) continue;
			Ed[S.top()].push_back(now);
			Ball[S.top()] += Ball[now];
			Size[S.top()] += Size[now];
		}
	}
	Sum = Ball[1];
}
int solve(int v, int plus)
{
	int you = Ball[v] + plus;
	if(Size[v] < you) return INF;
	if(Ed[v].size() == 0) return 0;
	int lv = Ed[v][0], rv = Ed[v][1];

	int val = INF;
	for(int re=0; re<1+you%2; re++)
	{
		int lb = you / 2 + re, rb = you - lb;
		int lu = lb - Ball[lv], ru = rb - Ball[rv];
		int l = solve(lv, lu), r = solve(rv, ru);
		if(l == INF || r == INF) continue;
//		printf("%d %d -> [%d %d] | [%d + %d + (%d)]\n", v, plus, lb, rb, l, r, min(abs(lu), abs(ru)));
		val = min(val, l + r + max(max(abs(lu) - abs(plus), abs(ru) - abs(plus)),0) );
	}
	return val;
}
void delGraph()
{
	for(int i=1; i<=N; i++)
	{
		vector<int> temp;
		Ed[i].swap(temp);
		Ball[i] = Size[i] = 0;
	}
	N = 0; Sum = 0;
}
int main()
{
	while(scanf("%s", tree) == 1)
	{
		initGraph();
		int ans = solve(1, 0);
		if(ans == INF) puts("impossible");
		else printf("%d\n", ans);
		delGraph();
	}
	return 0;
}
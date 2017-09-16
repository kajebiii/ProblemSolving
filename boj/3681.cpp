#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>
#include <stack>

using namespace std;

typedef long long ll;

const int INF = 0x7fffffff;

char Mb[1000000]; int N; char* p;
int Fast[1000000];
map<ll, int> M[20]; int maxD;
vector<pair<ll, int> > List;
void calc(int l, int r, int d)
{
	int m = Fast[l];
	if(m != -1)
	{
		calc(l+1, m, d+1);
		calc(m+1, r-1, d+1);
	}
	else
	{
		ll x;
		sscanf(p+l, "%lld", &x);
		M[d][x] = M[d][x] + 1;
		M[d][0] = M[d][0] + 1;
		maxD = max(maxD, d);
		List.push_back(make_pair(x, d));
	}
}
int main()
{
	int TC; scanf("%d", &TC); scanf(" ");
	for(int t=1; t<=TC; t++)
	{
		fgets(Mb, 1000000, stdin);
		p = Mb;
		N = strlen(Mb);
		for(int i=0; i<20; i++) M[i].clear();
		int val = 0, last = -1;
		for(int i=0; i<N; i++) Fast[i] = -1;
		stack<int> S;
		for(int i=0; i<N; i++)
		{
			if(Mb[i] == '[') S.push(i);
			if(Mb[i] == ']') S.pop();
			if(Mb[i] == ',') Fast[S.top()] = i;
		}
		maxD = 0;
		List.clear();
		calc(0, N-1, 0);

		int ans = INF, all = 0;
		for(int d=maxD; d>=0; d--) all += M[d][0];
		for(auto &x : List)
		{
			int now = x.first, nowd = x.second;
			if(now == 0) continue;
			for(; nowd<maxD; nowd++)
			{
				if(now % 2 == 1) {break;}
				now /= 2;
			}
			int nowAns = all;
			for(ll d=nowd, dNow = now; d>=0; d--, dNow *= 2)
				if(M[d].count(dNow) != 0) nowAns -= M[d][dNow];
			ans = min(ans, nowAns);
		}
		printf("%d\n", ans);
	}
	return 0;
}
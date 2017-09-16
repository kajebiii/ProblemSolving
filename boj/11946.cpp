#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

const int MAX_N = 1e2 + 10, MAX_M = 2e1 + 1;

int N, M, Res[MAX_N][MAX_M], Q;
bool AC[MAX_N][MAX_M];
struct TEAM
{
	int ix, ac, pa;
	TEAM(int i_, int a_, int p_) : ix(i_), ac(a_), pa(p_) {}
	bool operator<(const TEAM &o) const
	{
		if(ac != o.ac) return ac > o.ac;
		if(pa != o.pa) return pa < o.pa;
		return ix < o.ix;
	}
};

int main()
{
	scanf("%d%d%d", &N, &M, &Q);
	for(int _=0; _<Q; _++)
	{
		int t, n, m; char res[5];
		scanf("%d%d%d%s", &t, &n, &m, res);
		if(AC[n][m]) continue;
		if( (string)res == "AC")
		{
			AC[n][m] = true;
			Res[n][m] += t;
		}
		else
		{
			Res[n][m] += 20;
		}
	}
	vector<TEAM> val;
	for(int i=1; i<=N; i++)
	{
		int cnt = 0, sum = 0;
		for(int j=1; j<=M; j++) if(AC[i][j]) cnt++, sum += Res[i][j];
		val.push_back(TEAM(i, cnt, sum));
	}
	sort(val.begin(), val.end());
	for(auto &t : val)
		printf("%d %d %d\n", t.ix, t.ac, t.pa);
	return 0;
}
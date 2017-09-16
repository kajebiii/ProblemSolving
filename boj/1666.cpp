#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

const int MAX_N = 1e5 + 100;

struct IDX
{
	int P; vector<int> Val;
	IDX(int N)
	{
		for(P=1; P<N; P<<=1);
		Val = vector<int>(P*2, 0);
	}
	void update(int v, int k)
	{
		v += P;
		Val[v] = max(Val[v], k);
		while(v/=2) Val[v] = max(Val[v*2], Val[v*2+1]);
	}
	int getMax(int a, int b)
	{
		int result = 0;
		a += P; b += P;
		while(a <= b)
		{
			if(a%2 == 1) result = max(result, Val[a++]);
			if(b%2 == 0) result = max(result, Val[b--]);
			a/=2; b/=2;
		}
		return result;
	}
};
struct RECT
{
	pi ld, ru; int val;
	RECT(int x, int y, int a, int b) : ld(make_pair(x, y)), ru(make_pair(a, b)), val(0) {}
	RECT() : ld(make_pair(0, 0)), ru(make_pair(0, 0)), val(0) {}
};

vector<int> Ys; int yN;
int N; RECT R[MAX_N];
int ldIx[MAX_N], ruIx[MAX_N];
bool ldOp(int x, int y) { return R[x].ld < R[y].ld; }
bool ruOp(int x, int y) { return R[x].ru < R[y].ru; }
void init()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		int x, y, a, b;
		scanf("%d%d%d%d", &x, &y, &a, &b);
		R[i] = RECT(x, y, a, b);
		ldIx[i] = ruIx[i] = i;
		Ys.push_back(y); Ys.push_back(b);
	}
	sort(Ys.begin(), Ys.end());
	Ys.resize(unique(Ys.begin(), Ys.end()) - Ys.begin());
	for(int i=0; i<N; i++)
	{
		R[i].ld.second = lower_bound(Ys.begin(), Ys.end(), R[i].ld.second) - Ys.begin();
		R[i].ru.second = lower_bound(Ys.begin(), Ys.end(), R[i].ru.second) - Ys.begin();
	}
	sort(ldIx, ldIx+N, ldOp);
	sort(ruIx, ruIx+N, ruOp);
}
int main()
{
	init();
	IDX idx = IDX(Ys.size());
	int jp = 0, ans = 0;
	for(int p=0; p<N; p++)
	{
		int i = ldIx[p];
		while(jp < N && R[ruIx[jp]].ru.first < R[i].ld.first)
		{
			idx.update(R[ruIx[jp]].ru.second, R[ruIx[jp]].val);
			jp++;
		}
		R[i].val = idx.getMax(0, R[i].ld.second - 1) + 1;
		ans = max(R[i].val, ans);
	}
	printf("%d\n", ans);
	return 0;
}
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 100, INF = 0x7fffffff;


struct QR
{
	int t, x, y;
	QR(int t_, int x_, int y_ = 0) : t(t_), x(x_), y(y_) {}
};
struct PT
{
	int x, y, ix;
	PT(int ix_, int x_ = 0, int y_ = 0) : x(x_), y(y_), ix(ix_) {}
};
const bool cmpxy(PT A, PT B)
{
	if(A.y != B.y) return A.y < B.y;
	return A.x < B.x;
}
const bool cmpix(PT A, PT B)
{
	return A.ix < B.ix;
}

int N, Q;
vector<PT> Ps; vector<QR> Qs;
int SortIx[MAX_N];

struct IX
{
	vector<int> Val; int P, N;
	IX(int N_)
	{
		N = N_;
		for(P=1; P<N; P<<=1);
		Val = vector<int>(P*2, -1);
	}
	int getVal(int a)
	{
		if(a == -1) return -1;
		return Ps[a].x;
	}
	int getBigA(int a, int b)
	{
		if(a == -1) return b;
		if(b == -1) return a;
		if(Ps[a].x < Ps[b].x) return b;
		return a;
	}
	void update(int v, int k)
	{
		Val[v += P] = k;
		while(v /= 2) Val[v] = getBigA(Val[v*2], Val[v*2+1]);
	}
	int getMaxA(int a, int b)
	{
		int result = -1;
		a += P; b += P;
		while(a <= b)
		{
			if(a%2 == 1) result = max(result, getVal(Val[a++]));
			if(b%2 == 0) result = max(result, getVal(Val[b--]));
			a /= 2; b /= 2;
		}
		return result;
	}
	int getQ(int a, int b, int theX)
	{
//		printf("%d %d : %d\n", a, b, theX);
		int result = INF;
		for(int l=a, r=b; l <= r; )
		{
			int m = (l + r) / 2;
			int now = getMaxA(a, m);
			if(now >= theX)
			{
				result = min(result, m);
				r = m-1;
			}
			else l = m+1;
		}
		if(result == INF) result = -1;
		else result = Val[result+P];
		return result+1;
	}
};

void getInput()
{
	scanf("%d", &Q);
	int cnt = 0;
	for(int i=0; i<Q; i++)
	{
		scanf(" ");
		char o; int x, y;
		scanf("%c %d", &o, &x);
		if(o == 'D')
		{
			scanf("%d", &y);
			Qs.push_back(QR(0, x, y));
			Ps.push_back(PT(cnt++, x, y));
		}
		else
			Qs.push_back(QR(1, x));
	}
	sort(Ps.begin(), Ps.end(), cmpxy);
	for(int i=0; i<cnt; i++) SortIx[Ps[i].ix] = i;
	sort(Ps.begin(), Ps.end(), cmpix);
}
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	getInput();
	IX ix = IX(Ps.size());
	int cnt = 0;
	for(int i=0; i<Q; i++)
	{
		if(Qs[i].t == 0)
		{
			ix.update(SortIx[cnt], cnt);
			cnt++;
		}
		else
		{
			int x = Qs[i].x - 1;
			int result = ix.getQ(SortIx[x]+1, (int)Ps.size()-1, Ps[x].x);
			if(result == 0) puts("NE");
			else printf("%d\n", result);
		}
	}
	return 0;
}
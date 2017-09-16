#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct LN
{
	int x, y;
	LN() : x(0), y(0) {}
	LN(int x_, int y_) : x(x_), y(y_) {}
	bool operator<(const LN &o) const{return y==o.y?o.x<x:y<o.y;}
	bool operator==(const LN &o) const{return x==o.x && y==o.y;}
};
struct IDX
{
	int P; vector<int> Val;
	IDX(int n)
	{
		for(P=1; P<n; P<<=1);
		Val = vector<int>(2*P, 0);
	}
	void update(int v, int k)
	{
		Val[v+=P] = k;
		while(v/=2) Val[v] = max(Val[v*2], Val[v*2+1]);
	}
	int getMax(int a, int b)
	{
		int result = 0;
		a+=P;b+=P;
		while(a<=b)
		{
			if(a%2==1) result = max(result, Val[a++]);
			if(b%2==0) result = max(result, Val[b--]);
			a/=2;b/=2;
		}
		return result;
	}
};

int N;
vector<LN> Ls;
vector<int> Xs;

int main()
{
	scanf("%d", &N);
	for(int i=0, x, y, t; i<N; i++) scanf("%d%d%d", &t, &x, &y), Ls.push_back(LN(x, y)), Xs.push_back(x), Xs.push_back(y);
	sort(Xs.begin(), Xs.end()); Xs.erase(unique(Xs.begin(), Xs.end()), Xs.end());
	for(int i=0; i<N; i++) 
		Ls[i].x = lower_bound(Xs.begin(), Xs.end(), Ls[i].x) - Xs.begin(),
		Ls[i].y = lower_bound(Xs.begin(), Xs.end(), Ls[i].y) - Xs.begin();
	sort(Ls.begin(), Ls.end());

	IDX idx = IDX((int)Xs.size());
	int ans = 1;
	for(int i=0; i<N; i++)
	{
		//duplication processing
		if(i != 0 && Ls[i-1] == Ls[i]) continue;
		int now = idx.getMax(Ls[i].x, Ls[i].y) + 1;
		idx.update(Ls[i].x, now);
		ans = max(ans, now);
	}
	printf("%d\n", ans);
	return 0;
}
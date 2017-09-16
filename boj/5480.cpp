#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 100;

bool Visit[MAX_N];
int N, K, L;
struct LINE
{
	int co[2][2]; //0 xs, 1 ys (co[k][0] <= co[k][1]);
	int w;
};
vector<LINE> Ls;
vector<int> cord[2];
struct IDX
{
	int P; vector<vector<int> > val;
	IDX(int n)
	{
		for(P=1; P<n; P<<=1);
		val = vector<vector<int> >(2*P, vector<int>());
	}
	int arrange(int v)
	{
		int res = 0;
		while(!val[v].empty())
		{
			int now = val[v].back(); val[v].pop_back();
			if(Visit[now] == true) continue;
			Visit[now] = true;
			res = max(res, Ls[now].w);
		}
		return res;
	}
	int getMax(int v)
	{
		int res = 0;
		v += P;
		do{res = max(res, arrange(v));}while(v/=2);
		return res;
	}
	void update(int a, int b, int k)
	{
		a += P, b += P;
		while(a <= b)
		{
			if(a%2==1) val[a++].push_back(k);
			if(b%2==0) val[b--].push_back(k);
			a/=2; b/=2;
		}
	}
};
vector<pair<int, int>> Qs;
void init()
{
	scanf("%d%d%d", &N, &K, &L);
	for(int i=0; i<K; i++)
	{
		LINE temp;
		for(int k=0; k<2; k++) for(int j=0; j<2; j++) scanf("%d", &temp.co[j][k]);
		scanf("%d", &temp.w);
		for(int j=0; j<2; j++) if(temp.co[j][0] > temp.co[j][1]) swap(temp.co[j][0], temp.co[j][1]);
		Ls.push_back(temp);
		for(int j=0; j<2; j++) for(int k=0; k<2; k++)
			cord[j].push_back(temp.co[j][k]);
	}
	for(int i=0; i<L; i++)
	{
		int v, a; scanf("%d%d", &v, &a);
		cord[1-a].push_back(v);
		Qs.push_back(make_pair(v, a));
	}
	for(int k=0; k<2; k++)
	{
		sort(cord[k].begin(), cord[k].end());
		cord[k].erase(unique(cord[k].begin(), cord[k].end()), cord[k].end());
	}
	for(int i=0; i<K; i++)
		for(int j=0; j<2; j++) for(int k=0; k<2; k++)
			Ls[i].co[j][k] = lower_bound(cord[j].begin(), cord[j].end(), Ls[i].co[j][k]) - cord[j].begin();
	for(int i=0; i<L; i++)
	{
		int t = 1 - Qs[i].second;
		Qs[i].first = lower_bound(cord[t].begin(), cord[t].end(), Qs[i].first) - cord[t].begin();
	}
}
void del()
{
	for(int i=0; i<K; i++)
		Visit[i] = false;
	for(int k=0; k<2; k++)
	{
		vector<int> temp;
		cord[k].swap(temp);
	}
	{
		vector<LINE> tempL;
		vector<pair<int, int>> tempQ;
		Ls.swap(tempL);
		Qs.swap(tempQ);
	}
}
int main()
{
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		init();
		IDX idx[2] = {IDX((int)cord[0].size()), IDX((int)cord[1].size())};
		for(int i=0; i<K; i++) for(int j=0; j<2; j++)
			idx[j].update(Ls[i].co[j][0], Ls[i].co[j][1], i);
		for(int i=0; i<L; i++)
		{
			int v = Qs[i].first, t = 1 - Qs[i].second;
			printf("%d\n", idx[t].getMax(v));
		}
		del();
	}
	return 0;
}
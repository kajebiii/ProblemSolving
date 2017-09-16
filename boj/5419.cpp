#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
struct IT
{
	int P, *T;
	IT(int N)
	{
		for(P = 1; P<N; P<<=1);
		T = new int[2*P];
		for(int i=1; i<2*P; i++) T[i] = 0;
	}
	~IT()
	{
		delete T;
	}
	void update(int v)
	{
		T[v = v+P]++;
		while(v/=2) T[v] = T[v*2] + T[v*2+1];
	}
	int getSum(int a, int b)
	{
		a += P, b += P;
		int result = 0;
		while(a <= b)
		{
			if(a % 2 == 1) result += T[a++];
			if(b % 2 == 0) result += T[b--];
			a /= 2; b /= 2;
		}
		return result;
	}
};
bool cmp(pi x, pi y)
{
	if(x.first != y.first) return x.first < y.first;
	return x.second > y.second;
}

const int MAX_N = 1e5 + 100;
int N; vector<int> UniY;
pi Pt[MAX_N];

int main()
{
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d", &N);
		for(int i=0; i<N; i++) scanf("%d%d", &Pt[i].first, &Pt[i].second);
		UniY.clear();
		for(int i=0; i<N; i++) UniY.push_back(Pt[i].second);
		sort(UniY.begin(), UniY.end());
		UniY.resize(unique(UniY.begin(), UniY.end()) - UniY.begin());
		int uN = UniY.size();

		IT tree = IT(uN);
		sort(Pt, Pt+N, cmp);
		for(int i=0; i<N; i++) 
			Pt[i].second = lower_bound(UniY.begin(), UniY.end(), Pt[i].second) - UniY.begin();

		long long ans = 0;
		for(int i=0; i<N; i++)
		{
			ans += 1ll * tree.getSum(Pt[i].second, uN-1);
			tree.update(Pt[i].second);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
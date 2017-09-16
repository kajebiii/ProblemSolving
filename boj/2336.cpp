#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 5e5 + 100, INF = 0x7fffffff;

struct IDX
{
	int P; vector<int> Val;
	IDX(int n)
	{
		for(P=1; P<n; P<<=1);
		Val = vector<int>(P*2, INF);
	}
	void update(int v, int k) {Val[v+=P] = k; while(v/=2) {Val[v] = min(Val[v*2], Val[v*2+1]); } }
	int getMin(int a, int b)
	{
		int res = INF;
		a += P; b += P;
		while(a <= b)
		{
			if(a % 2 == 1) res = min(res, Val[a++]);
			if(b % 2 == 0) res = min(res, Val[b--]);
			a /= 2; b /= 2;
		}
		return res;
	}
};

int N; vector<int> L[3];
int Ix[MAX_N][3];
int main()
{
	scanf("%d", &N); for(int j=0; j<3; j++) for(int i=0, x; i<N; i++) scanf("%d", &x), L[j].push_back(x-1);
	IDX idx = IDX(N);
	for(int j=0; j<3; j++) for(int i=0; i<N; i++) Ix[L[j][i]][j] = i;

	int ans = 0;
	for(int a=0; a<N; a++)
	{
		int now = L[0][a], bix = Ix[now][1], cix = Ix[now][2];
		int minCinB = idx.getMin(0, bix-1);
		if(minCinB >= cix) ans++;
		idx.update(bix, cix);
	}
	printf("%d\n", ans);
	return 0;
}
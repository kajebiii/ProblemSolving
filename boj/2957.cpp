#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

long long ans = 0;
int N;
struct IDX
{
	vector<pi> Val;
	int P;
	IDX(int n)
	{
		for(P=1; P<n; P<<=1);
		Val = vector<pi>(2*P);
		for(int i=P; i<2*P; i++) Val[i] = make_pair(-1, i-P);
		for(int i=P-1; i>=1; i--) Val[i] = Val[i*2];
	}
	void update(int v, int k)
	{
		Val[v+=P].first = k;
		while(v/=2)
		{
			Val[v].first = (Val[v*2+1].first==-1?Val[v*2].first:Val[v*2+1].first);
			Val[v].second = (Val[v*2+1].first==-1?Val[v*2].second:Val[v*2+1].second);
		}
	}
	pi right(int v)
	{
		v += P;
		while(v)
		{
			if(v % 2 == 0 || v == 1) {if(Val[v].first != -1) return Val[v]; v--; }
			if( (v&(v-1)) == 0) break;
			v /= 2;
		}
		return make_pair(-1, -1);
	}
};

int main()
{
	scanf("%d", &N);
	
	IDX idx = IDX(N+1);
	idx.update(0, 0);

	for(int i=1; i<=N; i++)
	{
		int x; 
		scanf("%d", &x);
		//x = i;
		pi now = idx.right(x); 
		ans += now.first;
		now.first = now.first + 1;
		idx.update(x, now.first);
		idx.update(now.second, now.first);
		printf("%lld\n", ans);
	}

	return 0;
}
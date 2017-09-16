#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 100;

typedef long long ll;

struct IDX
{
	int P; vector<ll> Val;
	IDX(int n)
	{
		for(P=1; P<n; P<<=1);
		Val = vector<ll>(2*P, 0);
	}
	void update(int v, ll k) {Val[v+=P] += k; while(v/=2) {Val[v] = Val[v*2] + Val[v*2+1];}}
	ll getSum(int a, int b)
	{
		ll res = 0;
		a += P; b += P;
		while(a <= b)
		{
			if(a % 2 == 1) res += Val[a++];
			if(b % 2 == 0) res += Val[b--];
			a /= 2; b /= 2;
		}
		return res;
	}
};

int N, Nr[MAX_N];
ll Ans, Inv[MAX_N];
vector<int> Uni;


int main()
{
	scanf("%d", &N); for(int i=0; i<N; i++) scanf("%d", &Nr[i]), Uni.push_back(Nr[i]);
	sort(Uni.begin(), Uni.end());
	Uni.erase(unique(Uni.begin(), Uni.end()), Uni.end());
	for(int i=0; i<N; i++) Nr[i] = lower_bound(Uni.begin(), Uni.end(), Nr[i]) - Uni.begin();
	IDX idx = IDX((int)Uni.size());
	for(int i=N-1; i>=0; i--)
	{
		Inv[i] = idx.getSum(0, Nr[i]-1);
		idx.update(Nr[i], 1);
	}
	idx = IDX((int)Uni.size());
	for(int i=N-1; i>=0; i--)
	{
		Ans += idx.getSum(0, Nr[i]-1);
		idx.update(Nr[i], Inv[i]);
	}
	printf("%lld\n", Ans);
	return 0;
}
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e6 + 100;

typedef long long ll;

ll ggcd(ll a, ll b) {return b?ggcd(b, a%b):a;}

int N; ll Nr[MAX_N];
vector<int> Ed[MAX_N];
int One[MAX_N], Two[MAX_N], Pa[MAX_N];
int l[2] ={0, 0}, ixl = -1;
int t[2] ={0, 0}, ixt = -1;
int getMx = 0, getMx2 = 0;
ll ansA = 0x7fffffff, ansB = 1;

void getAns(int v)
{
	for(int w : Ed[v]) if(w != Pa[v])
	{
		Pa[w] = v;
		getAns(w);
	}
	if(Nr[v] <= 2)
	{
		getMx = getMx2 = 0;
		for(int w : Ed[v]) if(w != Pa[v])
			getMx  = max(getMx , One[w]),
			getMx2 = max(getMx2, Two[w]);
		if(Nr[v] == 1)
			One[v] = getMx + 1,
			Two[v] = getMx2 + 1;
		else
			Two[v] = getMx + 1, One[v] = 0;
	}
	else One[v] = Two[v] = 0;

	l[0] = l[1] = t[0] = t[1] = 0; ixl = ixt = -1;
	for(int w : Ed[v]) if(w != Pa[v])
	{
		if(l[0] < One[w])
		{
			ixl = w;
			l[1] = l[0];
			l[0] = One[w];
		}
		else if(l[1] < One[w])
			l[1] = One[w];

		
		if(t[0] < Two[w])
		{
			ixt = w;
			t[1] = t[0];
			t[0] = Two[w];
		}		
		else if(t[1] < Two[w])
			t[1] = Two[w];
		
	}
//	printf("%d (%d) : %lld / %d\n", v, One[v], Nr[v], (l[0] + l[1] + 1));
	if(ansA * (l[0] + l[1] + 1) > Nr[v] * ansB)
	{
		ansA = Nr[v];
		ansB = l[0] + l[1] + 1;
	}
	if(ixl != ixt)
	{
		if(t[0] != 0 && ansA * (l[0] + t[0] + 1) > Nr[v] * 2 * ansB)
		{
			ansA = Nr[v] * 2;
			ansB = l[0] + t[0] + 1;
		}
	}
	else
	{
		if(t[0] != 0 && ansA * (l[1] + t[0] + 1) > Nr[v] * 2 * ansB)
		{
			ansA = Nr[v] * 2;
			ansB = l[1] + t[0] + 1;
		}
		if(t[1] != 0 && ansA * (l[0] + t[1] + 1) > Nr[v] * 2 * ansB)
		{
			ansA = Nr[v] * 2;
			ansB = l[0] + t[1] + 1;
		}
	}
}
int main()
{
	scanf("%d", &N);
	for(int i=1, x, y; i<N; i++) scanf("%d%d", &x, &y), Ed[x].push_back(y), Ed[y].push_back(x);
	for(int i=1; i<=N; i++) scanf("%lld", &Nr[i]);
	int first = rand()%N + 1;
	Pa[first] = 0;
	getAns(first);

	ll gcd = ggcd(ansA, ansB);
	printf("%lld/%lld\n", ansA/gcd, ansB/gcd);
	return 0;
}
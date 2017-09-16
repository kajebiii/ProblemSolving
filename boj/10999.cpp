// =====================================================================================
//
//       Filename:  10999.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/15/2016 15:26:06
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>

const int MAX_N = 1e6 + 10;

struct NODE
{
	long long sum, plus;
	NODE *l, *r;
	NODE(){sum=plus=0, l=r=NULL;}
	void Make(int s, int e);
	void Update(int s, int e, int x, int y, long long  k);
	long long Get(int s, int e, int x, int y, long long p);
};
int N, K, A[MAX_N];

void NODE::Make(int s, int e)
{
	if(s == e)
	{
		sum = A[s];
		return;
	}

	if(l == NULL) l = new NODE(), r = new NODE();

	int m = (s + e) / 2;
	l->Make(s, m);
	r->Make(m+1, e);

	sum = l->sum + r->sum;
}

void NODE::Update(int s, int e, int x, int y, long long k)
{
	if(e < x || y < s) return;
	if(x <= s && e <= y)
	{
		sum += k * (e - s + 1);
		plus += k;
		return;
	}

	int m = (s + e) / 2;
	l->Update(s, m, x, y, k);
	r->Update(m+1, e, x, y, k);

	sum = l->sum + r->sum + plus * (e - s + 1);
}

long long NODE::Get(int s, int e, int x, int y, long long p)
{
	if(e < x || y < s) return 0;
	if(x <= s && e <= y)
		return sum + p * (e - s + 1);
	
	int m = (s + e) / 2;
	return l->Get(s, m, x, y, p+plus) + r->Get(m+1, e, x, y, p+plus);
}

int main()
{
	int a, b;
	scanf("%d%d%d", &N, &a, &b);
	K = a + b;

	for(int i=1; i<=N; i++)
		scanf("%d", &A[i]);
	
	NODE *Root = new NODE();
	Root->Make(1, N);

	for(int i=1; i<=K; i++)
	{
		int type; scanf("%d", &type);
		if(type == 1)
		{
			int x, y;
			long long k; 
			scanf("%d%d%lld", &x, &y, &k);
			Root->Update(1, N, x, y, k);
		}
		else
		{
			int x, y; scanf("%d%d", &x, &y);
			printf("%lld\n", Root->Get(1, N, x, y, 0));
		}
	}

	return 0;
}












#include <stdio.h>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

map<string, int> M;
void isNew(string &s)
{
	if(M.count(s) == 0) M[s] = M.size();
	return;
}

const int MAX_N = 2e5 + 100;

int UNF[MAX_N], S[MAX_N];
int Find(int v){return UNF[v]==v?v:UNF[v]=Find(UNF[v]);}
int Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if(a != b) UNF[a] = b, S[b] += S[a];
	return max(S[a], S[b]);
}
char AA[22], BB[22];
int main()
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		int N; scanf("%d", &N);
		for(int i=0; i<2*N; i++)
			UNF[i] = i, S[i] = 1;
		for(int i=0; i<N; i++)
		{
			string A, B;
			scanf("%s %s", AA, BB);
			A = AA, B = BB;
			isNew(A); isNew(B);
			printf("%d\n", Union(M[A], M[B]));
		}
		M.clear();
	}
	return 0;
}
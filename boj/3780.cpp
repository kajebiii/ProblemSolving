#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int MAX_N = 2e4 + 100;

typedef pair<int, int> pi;

int N, UNF[MAX_N], Length[MAX_N];
pi F(int v) { 
	if(UNF[v]==v) return make_pair(v,0);
	pi now = F(UNF[v]);
	UNF[v] = now.first;
	Length[v] += now.second;
	return make_pair(UNF[v], Length[v]);
}
void U(int a, int b)
{
	int p = abs(b-a) % 1000;
	int plus = F(b).second;
	a = F(a).first, b = F(b).first;
	Length[a] = p + plus;
	if(a == b) return;
	UNF[a] = b;
}
int main()
{
	int T; scanf("%d", &T);
	for(int t=0; t<T; t++)
	{
		scanf("%d", &N);scanf(" ");
		for(int i=1; i<=N; i++) UNF[i] = i;
		while(1)
		{
			char c; scanf("%c", &c);
			if(c == 'O') break;
			if(c == 'E')
			{
				int a; scanf("%d", &a); scanf(" ");
				printf("%d\n", F(a).second);
			}
			else // c == I
			{
				int a, b; scanf("%d%d", &a, &b); scanf(" ");
				U(a, b);
			}
		}
	}
	return 0;
}
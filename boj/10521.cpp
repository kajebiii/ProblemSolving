#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

const int MAX_N = 5e5 + 100;

ll Val[MAX_N];
int N, inD[MAX_N], type[MAX_N];
vector<int> Ed[MAX_N];

int main()
{
	ll H;
	scanf("%lld%d", &H, &N);
	Val[1] = H;
	for(int i=1, x, y; i<=N; i++) 
	{
		scanf(" ");
		char c; scanf("%c", &c);
		scanf("%d%d", &x, &y);
		type[i] = (c - 'L') / ('R' - 'L');
		Ed[i].push_back(x), Ed[i].push_back(y), inD[x]++, inD[y]++;
	}

	queue<int> Q;
	for(int i=0; i<=N; i++) if(inD[i] == 0) Q.push(i);

	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		if(v == 0) break;
		for(int w : Ed[v]) 
		{
			inD[w]--, Val[w] += Val[v] / 2;
			if(inD[w] == 0) Q.push(w);
		}
		Val[Ed[v][type[v]]] += Val[v] % 2;
	}

	for(int i=1; i<=N; i++)
	{
		if(Val[i] % 2 == 1)
			type[i] = 1 - type[i];

		printf("%c", 'L' + ('R' - 'L') * type[i]);
	}
	return 0;
}
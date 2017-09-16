#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<int, int> Dy; int CntN;
int N, K; vector<int> Nr;
vector<int> Change(int st)
{
	vector<int> val;
	for(int i=0; i<N; i++) val.push_back(st % 10), st /= 10;
	return val;
}


int main()
{
	scanf("%d%d", &N, &K);
	for(int i=0, x; i<N; i++) scanf("%d", &x), Nr.push_back(x);
	int firstS = 0;
	for(int i=N-1; i>=0; i--) firstS *= 10, firstS += Nr[i];

	Dy[firstS] = 1;
	queue<int> Q; Q.push(firstS);
	int last = 0;
	for(int i=N; i>=1; i--) last *= 10, last += i;
	
	while(!Q.empty())
	{
		int st = Q.front(); Q.pop();
		vector<int> now = Change(st);
		for(int i=0; i<N-K+1; i++)
		{
			reverse(now.begin()+i, now.begin()+i+K);
			int next = 0;
			for(int i=N-1; i>=0; i--) next *= 10, next += now[i];
			reverse(now.begin()+i, now.begin()+i+K);
			if(Dy[next] == 0) {Dy[next] = Dy[st] + 1; Q.push(next); }
		}
	}
	printf("%d\n", Dy[last]-1);

	return 0;
}
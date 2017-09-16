#include <stdio.h>
#include <queue>

using namespace std;

bool Chk[1001001];
int P[1001001], N;
void print(int n)
{
	if(n != N) print(P[n]);
	printf("%d ", n);
}
int main()
{
	scanf("%d", &N);

	queue< pair<int, int> > Q;
	Q.push(make_pair(N, 0));

	while(!Q.empty())
	{
		int now = Q.front().first;
		int how = Q.front().second;
		Q.pop();

		if(now == 1)
		{
			printf("%d\n", how);
			print(1);
			return 0;
		}
		if(now % 3 == 0)
			if(!Chk[now/3])
				Q.push(make_pair(now/3, how+1)), Chk[now/3] = true, P[now/3] = now;
		if(now % 2 == 0)
			if(!Chk[now/2])
				Q.push(make_pair(now/2, how+1)), Chk[now/2] = true, P[now/2] = now;
		if(!Chk[now-1])
			Q.push(make_pair(now-1, how+1)), Chk[now-1] = true, P[now-1] = now;
	}

	return 0;
}
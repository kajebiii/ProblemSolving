#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 5e5 + 100;
typedef pair<int, int> pi;

int N, M, toP[MAX_N][2];

void deleteNode(int x)
{
	int l = toP[x][0], r = toP[x][1];
	toP[l][1] = r; toP[r][0] = l;
}
void insertRight(int l, int x)
{
	int r = toP[l][1];
	toP[x][0] = l; toP[x][1] = r;
	toP[l][1] = x; toP[r][0] = x;
}
void getInput()
{
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++) toP[i][0] = i-1, toP[i][1] = i+1;
	toP[0][1] = 1; toP[N+1][0] = N;
	for(int t=0; t<M; t++)
	{
		scanf(" ");
		char k; int x, y;
		scanf("%c %d %d", &k, &x, &y);
		if(x == y) continue;
		if(k == 'A')
		{
			deleteNode(x);
			insertRight(toP[y][0], x);
		}
		else
		{
			deleteNode(x);
			insertRight(y, x);
		}
	}
}
pi Nr[MAX_N], L[MAX_N]; int K, prIx[MAX_N], isInLIS[MAX_N];
int main()
{
	getInput();
	int x = 0;
	for(int i=1; i<=N; i++) 
	{
		Nr[i] = make_pair(x = toP[x][1], i);
		int ix = lower_bound(L, L+K, Nr[i]) - L;
		if(ix != 0) prIx[i] = L[ix-1].second;
		if(ix == K) K++;
		L[ix] = Nr[i];
	}
	
	printf("%d\n", N - K);
	int ix = L[K-1].second;
	while(ix != 0)
	{
		isInLIS[ix] = 1;
		ix = prIx[ix];
	}
	int secondNr = Nr[1].first;
	sort(Nr+1, Nr+N+1);
	if(isInLIS[Nr[1].second] == 0) printf("A %d %d\n", 1, secondNr);
	for(int i=2; i<=N; i++)
		if(isInLIS[Nr[i].second] == 0)
			printf("B %d %d\n", i, i-1);

	return 0;
}
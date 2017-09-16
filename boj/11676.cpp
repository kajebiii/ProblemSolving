#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX_D = 1e2 + 10, MAX_R = 1e3 + 100;
const ll OVER = 1e15;

int Inco[MAX_D][MAX_D];
vector<int> Dish[MAX_D];
int Cnt[MAX_R];
int R, S, M, D, N;

void init()
{
	scanf("%d%d%d%d%d", &R, &S, &M, &D, &N);
	for(int i=1; i<=R; i++) scanf("%d", &Cnt[i]);
	for(int i=0; i<S+M+D; i++)
	{
		int k; scanf("%d", &k);
		while(k--)
		{
			int x; scanf("%d", &x);
			Dish[i].push_back(x);
		}
	}
	while(N--)
	{
		int x, y; scanf("%d%d", &x, &y); x--; y--;
		Inco[x][y] = Inco[y][x] = 1;
	}
}

bool isBig(ll val[2])
{
	return val[1] > 1000 || (val[1] == 1000 && val[0] > 0);
}
ll Ans[2];
int Chk[MAX_R];
int main()
{
	init();


	int chk = 0;
	for(int s=0; s<S; s++) for(int m=S; m<S+M; m++) for(int d=S+M; d<S+M+D; d++)
	{
		if(Inco[s][m] || Inco[m][d] || Inco[d][s]) continue;
		chk++;

		for(int x : Dish[s]) Chk[x] = chk;
		for(int x : Dish[m]) Chk[x] = chk;
		for(int x : Dish[d]) Chk[x] = chk;

		ll now[2] = {1, 0};
		for(int i=1; i<=R; i++)
		{
			if(Chk[i] != chk) continue;
			now[1] *= Cnt[i];
			now[0] *= Cnt[i];
			now[1] += (now[0] / OVER);
			now[0] %= OVER;

			if(isBig(now)) break;
		}
		for(int k=0; k<2; k++) Ans[k] += now[k];
		Ans[1] += (Ans[0] / OVER); Ans[0] %= OVER;
		if(isBig(Ans)) break;
	}

	if(isBig(Ans)) puts("too many");
	else
	{
		bool notZ = false;
		for(ll i=3, div = 1e3; i>=0; i--, div /= 10)
		{
			ll now = Ans[1] / div; Ans[1] %= div;
			if(now != 0) notZ = true;
			if(notZ) printf("%lld", now);
		}
		for(ll i=14, div = 1e14; i>=0; i--, div /= 10)
		{
			ll now = Ans[0] / div; Ans[0] %= div;
			if(now != 0) notZ = true;
			if(notZ) printf("%lld", now);
		}
		if(notZ == false) printf("0");
	}
	return 0;
}


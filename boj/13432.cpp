#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

const int MAX_N = 1e5 + 500;

int N, SA[MAX_N];
char S[MAX_N];

void getSA()
{
	int i, j, k;
	int m = 26;
	vector<int> cnt(max(N, m)+1, 0), x(N+1, 0), y(N+1, 0);
	for(i=1; i<=N; i++) cnt[x[i] = S[i] - 'a' + 1]++;
	for(i=1; i<=m; i++) cnt[i] += cnt[i-1];
	for(i=N; i>=1; i--) SA[cnt[x[i]]--] = i;
	for(int len=1, p=0; p<N; len<<=1, m = p)
	{
		for(p=0, i=N-len+1; i<=N; i++) y[++p] = i;
		for(i=1; i<=N; i++) if(SA[i] > len) y[++p] = SA[i] - len;
		for(i=0; i<=m; i++) cnt[i] = 0;
		for(i=1; i<=N; i++) cnt[x[y[i]]]++;
		for(i=1; i<=m; i++) cnt[i] += cnt[i-1];
		for(i=N; i>=1; i--) SA[cnt[x[y[i]]]--] = y[i];
		swap(x, y);
		p = 1; x[SA[1]] = 1;
		for(i=1; i<N; i++)
		{
			int a = SA[i], b = SA[i+1], al = SA[i]+len, bl = SA[i+1]+len;
			x[SA[i+1]] = (al <= N && bl <= N && y[a] == y[b] && y[al] == y[bl]) ? p : ++p;
		}
	}
}
int LCP[MAX_N];
int LCPs[MAX_N * 4][25];
void getLCP()
{
	int i, j, k=0;
	vector<int> rank(N+1, 0);
	for(i=1; i<=N; i++) rank[SA[i]] = i;
	for(i=1; i<=N; LCP[rank[i++]] = k)
		for(k ? k--:0, j = SA[rank[i]-1]; S[i+k] == S[j+k]; k++);
}

int Tree[MAX_N*4][2], P;
void update(int v, int k)
{
	v += P;
	Tree[v][0] = Tree[v][1] = k;
	if(k == -1) {Tree[v][0] = N+1; Tree[v][1] = -1;}
	while(v/=2)
	{
		Tree[v][0] = min(Tree[v*2][0], Tree[v*2+1][0]);
		Tree[v][1] = max(Tree[v*2][1], Tree[v*2+1][1]);
	}
}
pair<int, int> getMM(int a, int b)
{
	int miV = N+1, maV = -1;
	a += P, b += P;
	while(a <= b)
	{
		if(a % 2 == 1)
		{
			miV = min(miV, Tree[a][0]);
			maV = max(maV, Tree[a][1]);
			a++;
		}
		if(b % 2 == 0)
		{
			miV = min(miV, Tree[b][0]);
			maV = max(maV, Tree[b][1]);
			b--;
		}
		a /= 2;
		b /= 2;
	}
	return make_pair(miV, maV);
}
int main() 
{
	scanf("%s", S+1); N = strlen(S+1);
	getSA();
	getLCP();
	for(int i=1; i<N; i++) LCPs[i][0] = LCP[i] = LCP[i+1]; // LCP definition change;


	for(int p=1; p<19; p++)
		for(int i=1; i<N; i++)
			LCPs[i][p] = min(LCPs[i][p-1], LCPs[i+(1<<p-1)][p-1]);


	for(P=1; P<N+1; P<<=1);
	for(int i=0; i<P; i++)
	{
		if(i >= 1 && i <= N)
			update(i, SA[i]);
		else
			update(i, -1);
	}


	int past = 0;
	long long ans = 0;
	LCP[N] = 0;
	for(int i=1; i<N; i++)
	{
		if(past >= LCP[i])
		{
			past = LCP[i];
			continue;
		}
		int maxL = -1;
		for(int l=past+1, r=LCP[i]; l<=r; )
		{
			int m = (l+r) >> 1;
			int now = i;
			for(int p=19; p>=0; p--) if(LCPs[now][p] >= m) now += (1<<p);
			pair<int, int> val = getMM(i, now);
//			printf("i %d / m %d : [%d %d] -> [%d %d]\n", i, m, i, now, val.first, val.second);
			if(val.second - val.first >= m)
			{
				maxL = max(maxL, m);
				l = m+1;
			}
			else r = m-1;
		}
		if(maxL == -1) continue;
		else ans += (maxL - past);
		past = LCP[i];
	}
	printf("%lld\n", ans);
	return 0;
}











#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

const int MAX_N = 1e6 + 500;

int N, SA[MAX_N];
char S[MAX_N];

void getSA()
{
	int i;
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
void getLCP()
{
	int i, j, k=0;
	vector<int> rank(N+1, 0);
	for(i=1; i<=N; i++) rank[SA[i]] = i;
	for(i=1; i<=N; LCP[rank[i++]] = k)
		for(k ? k--:0, j = SA[rank[i]-1]; S[i+k] == S[j+k]; k++);
}
int Ans[MAX_N];
int main() {
	scanf("%s", S+1);
	N = strlen(S+1);
	reverse(S+1, S+N+1);
	getSA();
	getLCP();

	int base = -1;
	for(int i=1; i<=N; i++)
	{
		if(base != -1) Ans[SA[i]] = min(LCP[i], Ans[SA[i-1]]);
		if(SA[i] == 1) {
			base = i, Ans[SA[i]] = N;
			for(int j=i-1; j>=1; j--)
				Ans[SA[j]] = min(LCP[j+1], Ans[SA[j+1]]);
		}
	}
	int Q; scanf("%d", &Q);
	for(int i=1; i<=Q; i++)
	{
		int x; scanf("%d", &x);
		printf("%d\n", Ans[N+1-x]);
	}
	return 0;
}











#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <tuple>

using namespace std;

const int MAX_N = 2e4 + 500, MOD = 1e9 + 7;

int N, SA[MAX_N], Dy[MAX_N/2][4][3][2][2];
char S[MAX_N], A[MAX_N];

void getSA()
{
	int i, j, k;
	int m = 200;
	vector<int> cnt(max(N, m)+1, 0), x(N+1, 0), y(N+1, 0);
	for(i=1; i<=N; i++) cnt[x[i] = S[i] + 1]++;
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

int N0, N1;
int main() {
	scanf("%s", A+1); N0 = strlen(A+1);
	scanf("%s", S+1); N1 = strlen(S+1);
	N = N0 + N1 + 1;
	S[N1+1] = '#';
	for(int i=N1+2; i<=N; i++) S[i] = A[i-N1-1];
	getSA();
	getLCP();
	int ix = -1, ans = 0;
	for(int i=1; i<=N; i++) if(SA[i] == N1+2) ix = i;
	vector<int> List;
	for(int i=ix+1, l=N0; i<=N; i++)
	{
		l = min(l, LCP[i]);
		if(l == N0 && SA[i] <= N1) List.push_back(SA[i]);
	}
	for(int i=ix-1, l=N0; i>=1; i--)
	{
		l = min(l, LCP[i+1]);
		if(l == N0 && SA[i] <= N1) List.push_back(SA[i]);
	}
	int LN = List.size();
	sort(List.begin(), List.end());
	Dy[0][0][0][0][0] = 1;
	for(int i=1; i<=LN; i++)
	{
		int now = List[i-1];
		int nr[4] = {2, 3, 5, 7};
		int cnt[4] = {0, 0, 0, 0};
		for(int k=0; k<4; k++)
			while(now % nr[k] == 0)
			{
				now /= nr[k];
				cnt[k]++;
			}
		for(int a=0; a<4; a++) for(int b=0; b<3; b++)
			for(int c=0; c<2; c++) for(int d=0; d<2; d++)
			{
				int aa = min(3, a+cnt[0]);
				int bb = min(2, b+cnt[1]);
				int cc = min(1, c+cnt[2]);
				int dd = min(1, d+cnt[3]);
				Dy[i][aa][bb][cc][dd] += Dy[i-1][a][b][c][d];
				Dy[i][aa][bb][cc][dd] %= MOD;
				Dy[i][a][b][c][d] += Dy[i-1][a][b][c][d];
				Dy[i][a][b][c][d] %= MOD;
			}
	}
	printf("%d\n", Dy[LN][3][2][1][1]);
	return 0;
}











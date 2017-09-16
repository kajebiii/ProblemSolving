#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

typedef pair<int, int> pi;
#define mp make_pair
#define fi first
#define se second
#define pb push_back

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, 1), mp(1, 0), mp(0, -1)};
const int MAX_N = 2e5 + 200;

int K, N, L[2], S[MAX_N];
int SA[MAX_N];

void getSA()
{
	int i, j, k;
	int m = K + 10;
	vector<int> cnt(max(N, m)+1, 0), x(N+1, 0), y(N+1, 0);
	for(i=1; i<=N; i++) cnt[x[i] = S[i]]++;
	for(i=1; i<=m; i++) cnt[i] += cnt[i-1];
	for(i=N; i>=1; i--) SA[cnt[x[i]]--] = i;
	for(int len=1, p=0; p<N; len<<=1, m = p)
	{
		p=0;
		for(i=N-len+1; i<=N; i++) y[++p] = i;
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

int Ans[MAX_N], AnsN, F[MAX_N], MaxCnt[MAX_N];
int main()
{
	int T; cin >> T;
	while(T--)
	{
		scanf("%d%d%d%d", &K, &N, &L[0], &L[1]);
		int notIx = 1;
		for(int i=1; i<=N; i++) 
		{
			scanf("%d", &S[i]);
			if(S[i] <= K / 2) 
				S[i] = 1;
			else 
				S[i] = S[i] + 1;
		}
		MaxCnt[N+1] = 0;
		for(int i=N; i>=1; i--)
			if(S[i] == 1) MaxCnt[i] = 0;
			else MaxCnt[i] = MaxCnt[i+1] + 1;
		getSA();
		AnsN = -1;
		for(int i=N; i>=1; i--)
		{
			if(MaxCnt[SA[i]] >= L[0])
			{
				AnsN = min(MaxCnt[SA[i]], L[1]);
				for(int j=0; j<AnsN; j++) Ans[j] = S[SA[i] + j];
				break;
			}
		}
		printf("%d", Ans[0]-1);
		for(int i=1; i<AnsN; i++) printf("-%d", Ans[i]-1); printf("\n");
		F[0] = -1; for(int i=0, j=-1; i<AnsN; j<0||Ans[i]==Ans[j]?F[++i]=++j:j=F[j]);
		int cnt = 0;
		for(int i=0, j=0; i<N; )
			if(j < 0 || S[i+1] == Ans[j])
			{
				i++; j++;
				if(j == AnsN) {cnt++; j = F[j];}
			}else j = F[j];
		printf("%d\n", cnt);
	}
	return 0;
}

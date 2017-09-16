#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define REPO(i,n) for(int (i)=1; (i)<=(int)(n); (i)++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 1e6 + 30;

int M;
char S[MAX_N];
int F[MAX_N];

int main()
{
	cin.getline(S, MAX_N);
	M = (int)strlen(S);

	int i, j;
	for(F[i=0]=j=-1; i<M; j<0||S[i]==S[j]?F[++i]=++j:j=F[j]);
	for(int i=1; i<=M; i++) printf("%d : %d\n", i, F[i]);
	return 0;
}


int k = 0;
F[1] = 0;
for(int i=2;i<=|P|;i++) {
	while(k && P[k+1] != P[i]) k = F[k];
	if(P[k+1] == P[i]) k++;
	F[i] = k;
}
int k = 0;
for(int i=1;i<=|S|;i++) {
	while(k && P[k+1] != S[i]) k = F[k];
	if(P[k+1] == S[i]) k++;
	if(k == |P|) {
		// MATCHED WITH S[i-|P|+1  i]!!
		k = F[k];
	}
}

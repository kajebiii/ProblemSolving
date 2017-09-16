#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)((v).size()))
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 1e2 + 10;

int N, Ans[MAX_N]; pi Nr[MAX_N];
int main() {
	cin >> N;
	for(int q=0; q<N*(N-1)/2; q++) {
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		if(c < d) swap(a, b), swap(c, d);
		if(c == d) Nr[a].one++, Nr[b].one++;
		else Nr[a].one += 3;
	}
	for(int i=1; i<=N; i++) Nr[i].two = i;
	sort(Nr+1, Nr+N+1);
	reverse(Nr+1, Nr+N+1);

	for(int i=1, j=1; i<=N; i=j)
		while(Nr[j].one == Nr[i].one) Ans[Nr[j].two] = i, j++;
	for(int i=1; i<=N; i++) printf("%d\n", Ans[i]);
	return 0;
}



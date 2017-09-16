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

const int MAX_N = 50;

char S[MAX_N]; int N;
int main() {
	scanf("%s", S+1); N = strlen(S+1);
	bool isGood = true;
	for(int i=1; i<=N; i++) if(S[i] != S[N+1-i]) isGood = false;
	puts(isGood?"true":"false");
	return 0;
}



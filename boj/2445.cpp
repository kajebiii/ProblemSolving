#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
typedef pair<ll, int> pli;
const int INF = 0x3f2f1f0f;

const int MAX_N = 2e2 + 10;

char Star[MAX_N], Blank[MAX_N];
int main() {
	int N; scanf("%d", &N);
	for(int i=0; i<200; i++) Star[i] = '*', Blank[i] = ' ';
	for(int i=1; i<=N; i++) printf("%s%s%s\n", Star+200-i, Blank+200-(2*N-2*i), Star+200-i);
	for(int i=N-1; i>=1; i--) printf("%s%s%s\n", Star+200-i, Blank+200-(2*N-2*i), Star+200-i);
	return 0;
}
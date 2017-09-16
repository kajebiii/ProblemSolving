#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
typedef pair<ll, int> pli;
const int INF = 0x3f2f1f0f;

const int MAX_N = 1e2 + 10;

char Star[MAX_N], Blank[MAX_N];
int main() {
	int N; scanf("%d", &N);
	for(int i=0; i<100; i++) Star[i] = '*', Blank[i] = ' ';
	for(int i=1; i<=N; i++) 
		printf("%s%s\n", Blank+100-(N-i), Star+100-i);
	return 0;
}
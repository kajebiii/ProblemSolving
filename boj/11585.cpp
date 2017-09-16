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
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) { return mp(x.fi+y.fi, x.se+y.se); }

const int INF = 0x7fffffff;
const pi Ch[4] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1) };
const int MAX_N = 1e6 + 1000;

int gcd(int a, int b) { return b?gcd(b, a%b):a; }
int N, F[MAX_N];
char S[MAX_N], A[MAX_N * 2];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N;
	for(int i=0; i<N; i++) scanf("%*[ \n]%c", &S[i]);
	for(int i=0; i<N; i++) scanf("%*[ \n]%c", &A[i]);
	for(int i=N; i<2*N-1; i++) A[i] = A[i-N];

	F[0] = -1; for(int i=0, j=-1; i<N; j<0||S[i]==S[j]?F[++i]=++j:j=F[j]);

	int ans = 0;
	for(int i=0, j=0; i<2*N-1;)
	{
		if(j<0 || A[i] == S[j])
		{
			i++; j++;
			if(j == N)
			{
				ans++;
				j = F[j];
			}
		}
		else j = F[j];
	}
	int a = ans, b = N, g = gcd(a, b);
	printf("%d/%d\n", a/g, b/g);
	return 0;
}
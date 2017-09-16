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
pi operator +(const pi &x, const pi &y) { return mp(x.fi+y.fi, x.se+y.se); }

const int INF = 0x7fffffff;
const pi Ch[4] ={mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MOD = 1000000;

int N, Dy[5555];
char C[5555];
int main() {
	scanf("%s", C+1);
	N = (int)strlen(C+1);
	Dy[0] = 1;
	if(C[1] != '0') Dy[1] = 1;
	for(int i=2; i<=N; i++)
	{
		Dy[i] = 0;
		if(C[i] - '0' > 0) Dy[i] = Dy[i-1];
		int now = (C[i-1]-'0')*10 + C[i] - '0';
		if(now >= 10 && now <= 26) Dy[i] += Dy[i-2];
		Dy[i] %= MOD;
	}
	cout << Dy[N];
	return 0;
}

#include <stdio.h>
#include <functional>
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

int Bead[3];
int Dy[555][555];
int getDy(int a, int b)
{
	if(Dy[a][b] != 0) return Dy[a][b];
	int ans = 2;
	for(int i=0; i<3; i++) if(a >= Bead[i]) if(getDy(a - Bead[i], b) == 2) ans = 1;
	for(int i=0; i<3; i++) if(b >= Bead[i]) if(getDy(a, b - Bead[i]) == 2) ans = 1;

	Dy[a][b] = ans;
	return Dy[a][b];
}
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	for(int i=0; i<3; i++) scanf("%d", &Bead[i]);
	
	int TC = 5;

	while(TC--)
	{
		int a, b; cin >> a >> b;
		printf("%c\n", getDy(a, b) + 'A' - 1);
	}
	return 0;
}
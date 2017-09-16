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

ll N, B;
struct MAT
{
	int Nr[5][5];
	MAT() { for(int i=0; i<N; i++) for(int j=0; j<N; j++) Nr[i][j] = 0; }
	MAT operator*(MAT o)
	{
		MAT R = MAT();
		for(int i=0; i<N; i++) for(int j=0; j<N; j++) for(int k=0; k<N; k++)
			R.Nr[i][j] = (R.Nr[i][j] + Nr[i][k] * o.Nr[k][j]) % 1000;
		return R;
	}
};
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N >> B;
	MAT Ans, Pow;
	for(int i=0; i<N; i++) Ans.Nr[i][i] = 1;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d", &Pow.Nr[i][j]);

	while(B)
	{
		if(B%2 == 1) Ans = Ans * Pow;
		Pow = Pow * Pow;
		B /= 2;
	}
	for(int i=0; i<N; i++, puts("")) for(int j=0; j<N; j++)
		printf("%d ", Ans.Nr[i][j]);
	return 0;
}
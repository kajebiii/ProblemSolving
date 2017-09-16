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

int N, Nr[11111];
int getNr(int a, int b, int k)
{
	if(k < a) return -INF;
	if(k > b) return INF;
	return Nr[k];
}
void getAns(int a, int b)
{
	int now = Nr[a], n = b - a + 1;
	for(int i=0; i<n; i++)
	{
		int chb[2] ={ a, b }, chm[2] ={ 1, -1 };
		bool find = false;
		for(int k=0; k<2; k++)
		{
			int j = chb[k] + chm[k] * i;
			if(getNr(a+1, b, j) < now && getNr(a+1, b, j+1) > now)
			{
				getAns(a+1, j);
				getAns(j+1, b);
				find = true;
				break;
			}
		}
		if(find) break;
	}
	if(a <= b) printf("%d\n", Nr[a]);
	return;
}
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	while(scanf("%d", &Nr[N++]) == 1);
	N--;
	getAns(0, N-1);
	return 0;
}
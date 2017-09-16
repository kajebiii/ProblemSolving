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

char A[222];
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	int N; scanf("%d", &N); scanf("\n");
	for(int i=0; i<N; i++)
	{
		fgets(A, 222, stdin);
		bool flag = false;
		for(int k=0; A[k] != 0; k++)
		{
			if(A[k] == ' ') { if(!flag) printf("god"); flag = true;}
			else if(flag == true) printf("%c", A[k]);
		}
	}
	return 0;
}
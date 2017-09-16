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

const int MAX_N = 1e2 + 10;

int N, Nr[2][MAX_N];
int Dy[MAX_N][1111];
int toNr(int a, int b, int c)
{
	return a * 100 + b * 10 + c;
}
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	cin >> N;
	for(int k=0; k<2; k++) for(int i=1; i<=N; i++)
		scanf("%1d", &Nr[k][i]);
	for(int i=1; i<=N+1; i++) for(int j=0; j<1000; j++)
		Dy[i][j] = INF;
	Dy[1][toNr(Nr[0][1], Nr[0][2], Nr[0][3])] = 0;

	for(int i=1; i<=N; i++) for(int j=0; j<1000; j++)
	{
		if(Dy[i][j] == INF) continue;
		int A[3] ={ 0 }, M[3] ={ 0 };
		for(int k=2, p = j; k>=0; k--) M[k] = A[k] = p%10, p /= 10;

		int ch[3];
		for(ch[0]=0; ch[0]<10; ch[0]++) for(ch[1]=0; ch[1]<10; ch[1]++)
		{
			ch[2] = Nr[1][i];
			int cnt = 0;
			for(int k=0; k<3; k++) A[k] = M[k];
			for(int l=0; l<3; l++)
			{
				int t = (ch[l] - A[0] + 10) % 10;
				for(int k=0; k<3-l; k++) A[k] = (A[k] + t) % 10;
				cnt += (t + 2) / 3;
				if(t >= 7) cnt -= 2;
			}
			int next = A[1] * 100 + A[2] * 10 + Nr[0][i+3];
			Dy[i+1][next] = min(Dy[i+1][next], Dy[i][j] + cnt);
		}
	}
	int ans = Dy[N+1][0];

	cout << ans;

	return 0;
}
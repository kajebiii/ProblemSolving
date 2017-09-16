// =====================================================================================
//
//       Filename:  2007.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/09/2016 13:52:55
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

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
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const ll INFF = 1ll * INF * INF;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int N;
ll Cnt[111], P[11111], Chk[111][111], Pre[111][111];
bool findAns = false;
void find(int n)
{
	if(n == N*(N-1)/2)
	{
		findAns = true;
		return;
	}
	for(int i=N-1; i>=1; i--)
	{
		if(i != 1 && Cnt[i] >= Cnt[i-1]) continue;
		if(Cnt[i] > N) continue;
		if(Chk[i][Cnt[i]] != INFF && (Chk[i][Cnt[i]] + P[n])%2 == 1) continue;
		bool fR = false, fC = false;
		if(Pre[i-1][Cnt[i]] != INFF)
		{
			ll diff = P[n] - Pre[i-1][Cnt[i]];
			if(Chk[i-1][i] == INFF && Pre[i-1][i] != INFF && (Pre[i-1][i] + diff)%2==1)
				continue;
			if(Chk[i-1][i] == INFF) {fC = true;Chk[i-1][i] = diff;}
			else if(Chk[i-1][i] != diff) continue;
		}
		if(Pre[i][Cnt[i]-1] != INFF)
		{
			ll diff = P[n] - Pre[i][Cnt[i]-1];
			if(Chk[Cnt[i]-1][Cnt[i]] == INFF && Pre[Cnt[i]-1][Cnt[i]] != INFF && (Pre[Cnt[i]-1][Cnt[i]] + diff)%2==1)
				continue;
			if(Chk[Cnt[i]-1][Cnt[i]] == INFF) {fR = true;Chk[Cnt[i]-1][Cnt[i]] = diff;}
			else if(Chk[Cnt[i]-1][Cnt[i]] != diff) continue;
		}
		Pre[i][Cnt[i]] = P[n];
		Cnt[i]++;
		find(n+1);
		if(findAns) return;
		Cnt[i]--;
		Pre[i][Cnt[i]] = INFF;
		if(fC) Chk[i-1][i] = INFF;
		if(fR) Chk[Cnt[i]-1][Cnt[i]] = INFF;
	}
	return;
}
int main() {
	cin >> N; for(int i=0; i<N*(N-1)/2; i++) scanf("%lld", &P[i]);
	if(N == 1) {printf("0"); return 0;}
	if(N == 2) 
	{
		if(P[0] >= 0)printf("%d %lld", 0, P[0]); 
		else printf("%lld %d", P[0], 0);
		return 0;
	}
	for(int i=0; i<=N; i++) for(int j=0; j<=N; j++) 
		Chk[i][j] = Pre[i][j] = INFF;
	for(int i=1; i<N; i++) Cnt[i] = i+1; Cnt[0] = N+1;
	sort(P, P+N*(N-1)/2);
	find(0);

	if(findAns)
	{
		ll diff = Pre[1][3] - Pre[2][3];
		printf("%lld %lld", (Pre[1][2]+diff)/2, (Pre[1][2]-diff)/2);
		for(int i=3; i<=N; i++)
		{
			diff = Pre[i-2][i] - Pre[i-2][i-1];
			printf(" %lld", (Pre[i-1][i]+diff)/2);
		}
	}else puts("Impossible");
	return 0;
}











// =====================================================================================
//
//       Filename:  3651.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 15:41:45
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
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};

ll M;
vector<pair<ll, ll> > V;
ll C[3001][3001];
bool Not[3001][3001];
ll CC[20001][5];
long long getC(int a, int b)
{
	long long r = 1;
	for(int i=a; i>a-b; i--) r *= i;
	for(int i=1; i<=b; i++) r /= i;
	return r;
}
int main() {
	cin >> M;
	C[0][0] = CC[0][0] = 1;
	for(int i=1; i<=3000; i++)
	{
		C[i][0]=1; 
		for(int j=1; j<=i; j++) 
		{
			C[i][j] = C[i-1][j-1] + C[i-1][j];
			Not[i][j] = C[i][j] > M;
			if(Not[i-1][j-1] || Not[i-1][j])
				Not[i][j] = true;
			if(Not[i][j] == false && C[i][j] == M)
				V.push_back(mp(i, j));
		}
	}
	
	V.push_back(mp(M,1)); V.push_back(mp(M,M-1));
	int two = sqrt(M * 2);
	for(int i=-5; i<=5; i++)
		if(two + i >= 2 && getC(two+i, 2) == M)
			V.push_back(mp(two+i, 2)), V.push_back(mp(two+i, two+i-2));
	for(int k=3; k<=5; k++)
		for(int i=1; getC(i,k)<=M; i++)
			if(getC(i,k)==M) V.push_back(mp(i, k)), V.push_back(mp(i,i-k));

	sort(V.begin(), V.end());
	int N = unique(V.begin(), V.end()) - V.begin();
	V.resize(N);

	printf("%d", N);
	for(int i=0; i<V.size(); i++)
		printf("\n%lld %lld", V[i].fi, V[i].se);
	
	return 0;
}











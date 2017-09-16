// =====================================================================================
//
//       Filename:  2667.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/17/2016 22:29:23
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

#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

int UNF[999], Cnt[999];
int F(int x)
{
	return UNF[x]==0?x:UNF[x]=F(UNF[x]);
}
void UF(int x, int y)
{
	x = F(x); y = F(y);
	if(x == y) return;
	UNF[x] = y;
	Cnt[y] += Cnt[x];
}

int Map[30][30];

int main() {
	int N; cin >> N;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		scanf("%1d", &Map[i][j]), Cnt[i*N+j] = 1;
	int cx[4] = {0, -1, 0, +1};
	int cy[4] = {-1, 0, +1, 0};
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(Map[i][j] == 1) for(int k=0; k<4; k++)
			if(Map[i+cx[k]][j+cy[k]] == 1)
				UF(i*N+j, (i+cx[k])*N+(j+cy[k]));

	vector<int> V;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(UNF[i*N+j] == 0 && Map[i][j] == 1)
			V.push_back(Cnt[i*N+j]);
	sort(V.begin(), V.end());

	cout << V.size();
	for(int x : V)
		cout << endl << x;

	return 0;
}











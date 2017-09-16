// =====================================================================================
//
//       Filename:  10026.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/30/2016 14:17:49
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
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};
const int MAX_N = 111;

int UNF[MAX_N*MAX_N], N;
int F(int v) {return UNF[v]==v?v:UNF[v]=F(UNF[v]);}
void U(int a, int b) {UNF[F(a)] = F(b);}
char Map[MAX_N][MAX_N];
int Chk[MAX_N*MAX_N];
int main() {
	cin >> N;
	for(int i=1; i<=N; i++) scanf("%s", Map[i]+1);
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) UNF[i*N+j] = i*N+j;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		for(int k=0; k<4; k++)
		{
			int x = i+CX[k], y = j+CY[k];
			if(x<=0 || y<=0 || x>N || y>N) continue;
			if(Map[i][j] != Map[x][y]) continue;
			U(x*N+y, i*N+j);
		}
	int cnt;
	cnt = 0;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) 
		cnt += 1-Chk[F(i*N+j)], Chk[F(i*N+j)] = 1;
	printf("%d ", cnt);
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		for(int k=0; k<4; k++)
		{
			int x = i+CX[k], y = j+CY[k];
			if(x<=0 || y<=0 || x>N || y>N) continue;
			if(Map[i][j] != 'R' || Map[x][y] != 'G') continue;
			U(x*N+y, i*N+j);
		}
	cnt = 0;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) Chk[i*N+j] = 0;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) 
		cnt += 1-Chk[F(i*N+j)], Chk[F(i*N+j)] = 1;
	printf("%d", cnt);
	return 0;
}











// =====================================================================================
//
//       Filename:  13167.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/26/2016 13:34:15
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

using namespace std;

typedef pair<int, int> pi;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};
const int MAX_N = 5050;


int N;
vector<int> Xs, Ys;
map<int, int> IndexX;
int R[MAX_N][4];

void DoUnique(vector<int> &V)
{
	sort(V.begin(), V.end());
	int RN = unique(V.begin(), V.end()) - V.begin();
	V.resize(RN);
}

int UNF[MAX_N * 2][4]; //UNF, Chk, Max, Cnt
inline int F(int v)
{
	return UNF[v][0] == v ? v : UNF[v][0] = F(UNF[v][0]);
}
void U(int a, int b)
{
	int af = F(a), bf = F(b);
	if(af == bf) return;
	if(UNF[af][3] > UNF[bf][3]) swap(af, bf);
	UNF[af][0] = bf;
	if(UNF[af][3] == UNF[bf][3]) UNF[bf][3]++;
	UNF[bf][2] = max(UNF[bf][2], UNF[af][2]);
}

long long Ans[MAX_N];
int Dif[MAX_N * 2];
int Fast[MAX_N * 2], FN;
int main() {
	cin >> N;
	for(int i=0; i<N; i++) 
		for(int j=0; j<4; j++)
		{
			scanf("%d", &R[i][j]);
			if(j >= 2) 
				R[i][j] += R[i][j-2];
			if(j % 2)
				Ys.push_back(R[i][j]);
			else
				Xs.push_back(R[i][j]);
		}
	DoUnique(Xs);
	for(int i=0; i<(int)Xs.size(); i++)
		IndexX[Xs[i]] = i;
	for(int i=0; i<(int)Xs.size()-1; i++)
		Dif[i] = Xs[i+1] - Xs[i];
	DoUnique(Ys);
	
	int lastY = Ys.back();
	for(int i=0; i<N; i++)
	{
		R[i][0] = IndexX[R[i][0]];
		R[i][2] = IndexX[R[i][2]];
	}

	for(int i=0; i<(int)Xs.size()-1; i++)
	{
		UNF[i][0] = i;
		UNF[i][1] = 0;
		UNF[i][2] = i;
		UNF[i][3] = 1;
	}
	for(int j=0; j<(int)Ys.size()-1; j++)
	{
		int y = Ys[j], ny = Ys[j+1];
		if(lastY == y) break;

		FN = 0;
		for(int i=N-1; i>=0; i--)
		{
			if(R[i][1] > y || R[i][3] <= y) continue;
			int cnt = 0;
			int s = R[i][0], e = R[i][2] - 1;
			int now = s, last = s;
			while(now <= e)
			{
				if(!UNF[F(now)][1])
				{
					cnt += Dif[now];
					Fast[FN++] = now;
					UNF[F(now)][1] = 1;
				}
				U(last, now);
				last = now;
				now = UNF[F(now)][2] + 1;
			}
			Ans[i] += 1ll * (ny - y) * cnt;
		}
		for(int i=0; i<FN; i++)
		{
			int &now = Fast[i];
			UNF[now][0] = now;
			UNF[now][1] = 0;
			UNF[now][2] = now;
			UNF[now][3] = 1;
		}
	}
	for(int i=0; i<N; i++)
		printf("%lld\n", Ans[i]);
	return 0;
}











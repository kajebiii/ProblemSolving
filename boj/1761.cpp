// =====================================================================================
//
//       Filename:  1761.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/12/2016 15:10:50
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 4e4 + 50;
const int LOG_N = 20;

int N;
vector< pair<int, int> > V[MAX_N];
pair<int, int> P[MAX_N][LOG_N];
int D[MAX_N];

void DFS(int v, int p)
{
	for(auto data : V[v])
	{
		int w = data.first;
		int c = data.second;
		if(w == p) continue;
		D[w] = D[v] + 1; 
		P[w][0] = make_pair(v, c);
		DFS(w, v);
	}
}

int getLength(int v, int w)
{
	if(D[v] < D[w]) swap(v, w);

	int result = 0;
	for(int i=0; i<LOG_N; i++)
		if( (D[v] - D[w]) & (1 << i) )
		{
			result += P[v][i].second;
			v = P[v][i].first;
		}	
	if(v == w) return result;

	for(int i=LOG_N-1; i>=0; i--)
	{
		if(P[v][i].first != P[w][i].first)
		{
			result += P[v][i].second;
			result += P[w][i].second;
			v = P[v][i].first;
			w = P[w][i].first;
		}
	}

	return result + P[v][0].second + P[w][0].second;
}	

int main()
{
	scanf("%d", &N);
	for(int i=1; i<N; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		V[x].push_back(make_pair(y, z));
		V[y].push_back(make_pair(x, z));
	}

	DFS(1, 0);

	for(int j=1; j<LOG_N; j++)
		for(int i=1; i<=N; i++)
			P[i][j] = make_pair(P[P[i][j-1].first][j-1].first, P[P[i][j-1].first][j-1].second + P[i][j-1].second);
	int M;
	scanf("%d", &M);

	for(; M--; )
	{
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", getLength(x, y));
	}

	return 0;
}











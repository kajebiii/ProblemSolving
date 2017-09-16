// =====================================================================================
//
//       Filename:  1867.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/12/2016 19:10:19
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <vector>

using namespace std;

const int MAX_N = 5e2 + 10;

int N, K;

int bMatch[MAX_N];
bool isVisit[MAX_N];
vector<int> V[MAX_N];

bool findMatch(int v)
{
	if(isVisit[v] == true) return false;
	isVisit[v] = true;

	for(auto w : V[v])
	{
		if(bMatch[w] == 0 || findMatch(bMatch[w]))
		{
			bMatch[w] = v;
			return true;
		}
	}
	return false;
}

int main()
{
	scanf("%d%d", &N, &K);

	for(int i=0; i<K; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		V[x].push_back(y);
	}

	int result = 0;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++) isVisit[j] = false;
		if(findMatch(i)) ++result;
	}

	printf("%d\n", result);

	return 0;
}






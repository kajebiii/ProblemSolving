// =====================================================================================
//
//       Filename:  1963.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 15:31:44
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

bool notPrime[11111];
int Dis[11111];

int main() {
	int T; cin >> T;
	for(int i=2; i<=9999; i++)
	{
		if(notPrime[i]) continue;
		for(int j=i*2; j<=9999; j+=i)
			notPrime[j] = true;
	}
	while(T--)
	{
		int A, B; scanf("%d%d", &A, &B);
		for(int i=1000; i<=9999; i++)
			Dis[i] = -1;
		
		queue<int> Q;
		Q.push(A);
		Dis[A] = 0;
		
		while(!Q.empty())
		{
			int now = Q.front(); Q.pop();
			if(now == B)
			{
				printf("%d\n", Dis[B]);
				break;
			}
			for(int p=1; p<10000; p*=10)
			{
				for(int i=0; i<10; i++)
				{
					int next = now - (now % (p*10)) / p * p + i * p;
					if(next < 1000 || next >= 10000) continue;
					if(notPrime[next] == true) continue;
					if(Dis[next] != -1) continue;
					Q.push(next);
					Dis[next] = Dis[now] + 1;
				}
			}
		}
	}
	return 0;
}











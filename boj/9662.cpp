// =====================================================================================
//
//       Filename:  9662.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/21/2016 16:22:00
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

const int MAX_K = 22;


int Nr[MAX_K];
int F[10001];
bool Dy[10001];

int main() {
	int M, K; scanf("%d%d", &M, &K);
	for(int i=0; i<K; i++) scanf("%d", &Nr[i]);
	for(int i=0; i<Nr[0]; i++) Dy[i] = false;

	int ans = 0;
	for(int i=0; i<=M; i++)
	{
		if(Dy[i] == false)
		{
			if(i != 0) ans++;
			//printf("%d : CY\n", i);
			for(int j=0; j<K; j++)
				if(i+Nr[j] <= M)
					Dy[i+Nr[j]] = true;
		}
		else
		{
			//printf("%d : SK\n", i);
		}
		for(int j=80; j*2<=i+1; j++)
		{
			bool flag = true;
			for(int k=0; k<j; k++)
				if(Dy[i-k] != Dy[i-j-k])
					flag = false;
			if(!flag) continue;
			int sum = 0;
			for(int k=0; k<j; k++)
				if(!Dy[i-k]) sum++;
			ans += (M - i) / j * sum;
			for(int k=0; k<(M-i)%j; k++)
				if(!Dy[i-j+1+k]) ans++;
			i = M;
			break;
		}
	}
	printf("%d\n", ans);

	return 0;
}











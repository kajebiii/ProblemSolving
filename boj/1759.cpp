// =====================================================================================
//
//       Filename:  1759.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/19/2016 11:57:49
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

const int MAX_C = 15;

int L, C;
char A[MAX_C];
int Ch[MAX_C];

void find(int l, int x, int y, int n)
{
	if(l == C)
	{
		if(n != L) return;
		if(x < 1 || y < 2) return;
		for(int i=0; i<C; i++)
			if(Ch[i] == 1)
				printf("%c", A[i]);
		printf("\n");
		return;
	}
	if(n > L) return;
	char k = A[l];
	if(k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u')
		x++;
	else
		y++;
	Ch[l] = 1;
	find(l+1, x, y, n+1);
	Ch[l] = 0;
	if(k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u')
		x--;
	else
		y--;
	find(l+1, x, y, n);
}

int main() {
	cin >> L >> C;
	for(int i=0; i<C; i++) cin >> A[i];
	sort(A, A+C);
	find(0, 0, 0, 0);
	return 0;
}











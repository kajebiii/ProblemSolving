// =====================================================================================
//
//       Filename:  2456.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 18:19:33
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

struct SC
{
	int A[4];
	int index;
	SC()
	{
		for(int i=0; i<4; i++)
			A[i] = 0;
	}
	const int getSum() const 
	{
		int sum = 0;
		for(int i=1; i<4; i++)
			sum += i*A[i];
		return sum;
	}
	const bool operator<(const SC &other) const
	{
		int sum[2] = {getSum(), other.getSum()};
		if(sum[0] != sum[1]) return sum[0] < sum[1];
		for(int i=3; i>=1; i--)
			if(A[i] < other.A[i])
				return true;
			else if(A[i] > other.A[i])
				return false;
		return false;
	}
}S[3];
int main() {
	int N; cin >> N;
	for(int i=0; i<3; i++) S[i].index = i+1;
	for(; N--;)
		for(int x, i=0; i<3; i++)
			scanf("%d", &x), S[i].A[x]++;
	sort(S, S+3);
	if( !(S[2] < S[1]) && !(S[1] < S[2]) )
		cout << 0 << " " << S[2].getSum();
	else
		cout << S[2].index << " " << S[2].getSum();

	return 0;
}











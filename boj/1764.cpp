// =====================================================================================
//
//       Filename:  1764.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/27/2016 23:44:38
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

vector<string> A, B;
int main() {
	int N, M; cin >> N >> M;
	int a = 0, b = 0;
	for(int i=0; i<N; i++)
	{
		string S; cin >> S;
		A.push_back(S);
	}
	for(int i=0; i<M; i++)
	{
		string S; cin >> S;
		B.push_back(S);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	vector<string> Ans;
	while(a < N || b < M)
	{
		if(a == N) {b++; continue;}
		if(b == M) {a++; continue;}
		if(A[a] == B[b])
		{
			Ans.push_back(A[a]);
			a++; b++;
			continue;
		}
		if(A[a] < B[b])
			a++;
		else
			b++;
	}
	printf("%d", (int)Ans.size());
	for(string x : Ans)
		cout << endl << x;
	return 0;
}











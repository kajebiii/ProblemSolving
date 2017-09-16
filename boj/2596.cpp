// =====================================================================================
//
//       Filename:  2596.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/08/2016 02:57:56
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
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int Data[8][6] = {
	{0,0,0,0,0,0},
	{0,0,1,1,1,1},
	{0,1,0,0,1,1},
	{0,1,1,1,0,0},
	{1,0,0,1,1,0},
	{1,0,1,0,0,1},
	{1,1,0,1,0,1},
	{1,1,1,0,1,0}
}, A[6];
vector<char> Ans;
int main() {
	int N; cin >> N;
	for(int k=0; k<N; k++)
	{
		for(int i=0; i<6; i++) scanf("%1d", &A[i]);
		
		bool find = false;
		for(int l=0; l<8; l++)
		{
			int cnt = 0;
			for(int i=0; i<6; i++) if(A[i] != Data[l][i]) cnt++;
			if(cnt <= 1) 
			{
				find = true;
				Ans.pb('A'+l);
			}
		}
		if(find == false)
		{
			printf("%d", k+1);
			return 0;
		}
	}
	for(char x : Ans) printf("%c", x);
	return 0;
}











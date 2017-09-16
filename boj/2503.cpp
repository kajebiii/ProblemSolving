// =====================================================================================
//
//       Filename:  2503.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 17:33:31
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
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};
const int MAX_N = 111;

int Nr[MAX_N][5], N;
bool isOK(int a[3], int b[5])
{
	int st = 0, ba = 0;
	for(int i=0; i<3; i++) if(a[i] == b[i]) st++;
	for(int i=0; i<3; i++) for(int j=0; j<3; j++)
		if(i!=j) if(a[i] == b[j]) ba++;
	return b[3] == st && b[4] == ba;
}
int main() {
	cin >> N;
	for(int i=1; i<=N; i++) for(int j=0; j<5; j++) scanf("%1d", &Nr[i][j]);
	int A[3], ans = 0;
	for(A[0]=1; A[0]<10; A[0]++) for(A[1]=1; A[1]<10; A[1]++) for(A[2]=1; A[2]<10; A[2]++)
		if(A[0]!=A[1] && A[0]!=A[2] && A[1]!=A[2])
		{
			bool flag = true;
			for(int i=1; i<=N; i++)
				if(!isOK(A, Nr[i]))
					flag = false;
			if(flag) ans++;
		}
	cout << ans;
	return 0;
}











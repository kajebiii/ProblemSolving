// =====================================================================================
//
//       Filename:  1780.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 16:28:24
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

int Map[2555][2555];
int Cnt[3];
void getSum(int a, int b, int k)
{
	bool chk[3] = {0,0,0};
	for(int i=a; i<a+k; i++) for(int j=b; j<b+k; j++) chk[Map[i][j]+1]=true;
	int cnt = 0; for(int i=0; i<3; i++) if(chk[i]) cnt++;
	if(cnt == 1)
	{
		for(int i=0; i<3; i++) if(chk[i]) Cnt[i]++;
		return;
	}
	else
	{
		for(int i=0; i<3; i++) for(int j=0; j<3; j++)
			getSum(a+i*(k/3), b+j*(k/3), k/3);
	}
}
int main() {
	int N; cin >> N;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d", &Map[i][j]);
	getSum(0,0,N);
	for(int i=0; i<3; i++) printf("%d\n", Cnt[i]);
	return 0;
}











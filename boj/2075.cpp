// =====================================================================================
//
//       Filename:  2075.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/07/2016 22:09:29
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

const int INF = 0x7fffffff;

priority_queue<int, vector<int>, greater<int> > Q;
int N;

int main() {
	cin >> N;
	for(int i=0, x; i<N; i++) scanf("%d", &x), Q.push(x);
	for(int i=1; i<N; i++) for(int j=0, x; j<N; j++)
	{
		scanf("%d", &x);
		int now = Q.top();
		if(now < x) {Q.pop(); Q.push(x);}
	}
	printf("%d\n", Q.top());
	return 0;
}











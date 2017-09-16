// =====================================================================================
//
//       Filename:  1063.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 14:13:33
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <map>
#include <string>
#include <iostream>

#define pi pair<int, int>
#define mp make_pair

using namespace std;

map<string, pi> M;
pi K, R;

pi operator+(const pi &x, const pi &y)
{
	return mp(x.first + y.first, x.second + y.second);
}
pi getInput()
{
	char x; int y; scanf("%c%d ", &x, &y);
	return make_pair(y, x-'A'+1);
}
bool isOK(pi &x)
{
	if(x.first > 0 && x.second > 0 && x.first <= 8 && x.second <= 8) return true;
	return false;
}
void printWhere(pi &x)
{
	printf("%c", x.second + 'A' - 1);
	printf("%d\n", x.first);
	return;
}

int main()
{
	K = getInput();
	R = getInput();
	int N; scanf("%d", &N);
	M["R" ] = mp(+0, +1);
	M["L" ] = mp(+0, -1);
	M["T" ] = mp(+1, +0);
	M["B" ] = mp(-1, +0);
	M["RT"] = mp(+1, +1);
	M["LT"] = mp(+1, -1);
	M["RB"] = mp(-1, +1);
	M["LB"] = mp(-1, -1);
	for(int i=0; i<N; i++)
	{
		string now;
		cin >> now;
		pi KK = K, RR = R;

		K = K + M[now];
		if(K == R)
			R = K + M[now];
		if(isOK(K) == false || isOK(R) == false)
			K = KK, R = RR;
	}
	printWhere(K);
	printWhere(R);

	return 0;
}

























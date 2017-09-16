//
//  main.cpp
//  1331
//
//  Created by KJBS2 on 03/07/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

bool Check[9][9];

void setCheck(pair<int, int> A)
{
	Check[A.first][A.second] = true;
	return;
}
bool getCheck(pair<int, int> A)
{
	return Check[A.first][A.second];
}
bool isTrue(pair<int, int> A, pair<int, int> B)
{
	int a = abs(A.first - B.first);
	int b = abs(A.second - B.second);
	if( (a+b) != 3 ) return false;
	if(a == 1 || a == 2) return true;
	return false;
}
pair<int, int> getIp()
{
	int a = getchar() - 'A' + 1;
	int b = getchar() - '1' + 1;
	getchar();
	return make_pair(a, b);
}

int main()
{
	pair<int, int> First = getIp();
	pair<int, int> past = First;
	setCheck(past);
	for(int i=1; i<36; i++)
	{
		pair<int, int> now = getIp();
		if(getCheck(now) == true || isTrue(past, now) == false)
		{
			printf("Invalid\n");
			return 0;
		}
		setCheck(now);
		past = now;
	}
	if(isTrue(past, First) == false)
		printf("Invalid\n");
	else
		printf("Valid\n");
	return 0;
}

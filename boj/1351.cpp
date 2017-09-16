//
//  main.cpp
//  1351
//
//  Created by KJBS2 on 03/07/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <map>

using namespace std;

map<long long, long long> Dy;

long long N;
int P, Q;

long long getA(long long n)
{
	if(n == 0) return 1;
	if(Dy.count(n) != 0) return Dy[n];
	long long result = 0;
	result += getA(n/P);
	result += getA(n/Q);
	Dy[n] = result;

	return result;
}

int main()
{
	scanf("%lld%d%d", &N, &P, &Q);
	printf("%lld\n", getA(N));
	return 0;
}


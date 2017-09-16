//
//  main.cpp
//  1040
//
//  Created by KJBS2 on 05/19/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;


int Number[20], Length;
int K;

void INPUT() {
	char input[20];
	scanf("%s", input);

	Length = strlen(input);
	for(int i = 0; i < Length; i++)
		Number[i] = input[i] - '0';
	scanf("%d", &K);
}

int nowNumber[20];
int checkChange(int check, int i) {
	if((check & (1<<i)) == 0)
		return check;
	return check - (1<<i);
}
bool getResult(int n, bool isBig, int choose[], int check) {
	if(n == Length)
	{
		if(check == 0)
			return true;
		else
			return false;
	}

	for(int i = 0; i < 10; i++) {
		if(choose[i] == 0) continue;
		if(isBig == true)
		{
			nowNumber[n] = i;
			if(getResult(n+1, true, choose, checkChange(check, i))) return true;
			continue;
		}
		if(i < Number[n]) continue;
		else if(i == Number[n])
		{
			nowNumber[n] = i;
			if(getResult(n+1, false, choose, checkChange(check, i))) return true;
		}
		else if(i > Number[n])
		{
			nowNumber[n] = i;
			if(getResult(n+1, true, choose, checkChange(check, i))) return true;
		}

	}
	return false;
}
void PROCESS() {
	if(Length < K) {
		printf("10");
		for(int i = 0; i < K-2; i++)
			printf("%d", i+2);
		return;
	}
	int choose[10];
	for(int i=0; i<10; i++)
		if(i < 10-K) 
			choose[i] = 0;
		else
			choose[i] = 1;

	int minResult[20];
	bool isFind = false;
	do
	{
		int firstCheck = 0;
		for(int i = 0; i < 10; i++)
			if(choose[i] == 1)
				firstCheck += 1 << i;

		if(getResult(0, 0, choose, firstCheck) == false) continue;	
		bool flag = false;
		for(int i = 0; i < Length; i++)
			if(minResult[i] > nowNumber[i]) 
			{
				flag = true;
				break;
			}
			else if(minResult[i] < nowNumber[i]) 
			{
				flag = false;
				break;
			}
		if(flag == false && isFind == true) continue;
		isFind = true;
		for(int i = 0; i < Length; i++)
			minResult[i] = nowNumber[i];
	}while(next_permutation(choose, choose + 10));

	if(isFind == false) 
	{
		printf("10");
		for(int i = 0; i < Length - K + 1; i++)
			printf("0");
		for(int i = 0; i < K - 2; i++)
			printf("%d", i+2);
	}
	else
	{
		for(int i = 0; i < Length; i++)
			printf("%d", minResult[i]);
	}

}

int main() {
	INPUT();
	PROCESS();
	return 0;
}





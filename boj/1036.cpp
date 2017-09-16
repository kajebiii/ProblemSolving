//
//  main.cpp
//  1036
//
//  Created by KJBS2 on 03/08/2016.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int charToInt(char x) {
	if(x <= '9') return x - '0';
	return x - 'A' + 10;
}
int intToChar(int x) {
	if(x <= 9) return x + '0';
	return x + 'A' - 10;
}

int N, K;

struct SYSTEM{
	int number;
	int system[55];
	SYSTEM() {
		number = 0;
		for(int i = 0; i < 55; i++)
			system[i] = 0;
	}
	SYSTEM& operator+=(const SYSTEM& other) {
		for(int i = 0; i < 55; i++) {
			this -> system[i] += other.system[i];
			if(i == 54) break;
			this -> system[i+1] += this -> system[i] / 36;
			this -> system[i] %= 36;
		}
		return *this;
	}
	bool operator<(const SYSTEM& other) const{
		for(int i = 54; i >= 0; i--) {
			if(this -> system[i] > other.system[i]) return false;
			if(this -> system[i] < other.system[i]) return true;
		}
		return this -> number < other.number;
	}
	void print() {
		int notZero = -1;
		for(int i = 54; i >= 0; i--) 
			if(this -> system[i] != 0) {
				notZero = i;
				break;
			}

		for(int i = notZero; i >= 0; i--)
			printf("%c", intToChar(this -> system[i]));

		printf("\n");
		
	}
}Number[36], Sum;

int main() {
	scanf("%d", &N);

	for(int i = 0; i < 36; i++)
		Number[i].number = i;

	char inputData[99];
	for(int i = 0; i < N; i++) {
		scanf("%s", inputData);

		SYSTEM temp = SYSTEM();
		for(int j = strlen(inputData) - 1, ix = 0; j >= 0; j--, ix++) {
			int nowInt = charToInt(inputData[j]);
			Number[nowInt].system[ix] += charToInt('Z') - nowInt;
			temp.system[ix] += nowInt;
		}
		Sum += temp;

	}

	for(int i = 0; i < 36; i++)
		Number[i] += SYSTEM();

	scanf("%d", &K);

	sort(Number, Number + 36);

	for(int i = 35; i >= 36 - K; i--)
		Sum += Number[i];

	Sum.print();

	return 0;
}








#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

const int MAX_N = 8e2 + 100;

int Val[40][1111], N;

int main() {
	int T; scanf("%d", &T);
	map<char, int> Mp;
	Mp['b'] = 0; Mp['g'] = 1; Mp['r'] = 2; Mp['y'] = 3;
	while(T--) {
		scanf("%d", &N);
		for(int j=0; j<4; j++) for(int i=0; i<111; i++) Val[j][i] = false;
		for(int i=0; i<N; i++) {
			int d; char c[10]; scanf(" %d%s", &d, c);
			Val[Mp[c[0]]][d] = true;
		}
		bool isCan = false;
		for(int j=0; j<4; j++) for(int i=0; i<=105; i++)
			if(Val[j][i] & Val[j][i+1] & Val[j][i+2])
				isCan = true;
		for(int i=0; i<111; i++) for(int j=0; j<4; j++)
			if(Val[j][i] & Val[(j+1)%4][i] & Val[(j+2)%4][i])
				isCan = true;
		if(isCan) puts("YES"); else puts("NO");
	}
	return 0;
}
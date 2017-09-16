#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e2 + 10, MAX_S = 2e3 + 10;;

int N, E, Nr[MAX_N];
bool isPos[MAX_N * MAX_S];

int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d", &N, &E);
		E = (E+1) / 2;
		int sum = 0;
		for(int i=0; i<N; i++) scanf("%d", &Nr[i]), sum += Nr[i];

		if(E > sum) {puts("FULL"); continue;}

		isPos[0] = true;
		for(int i=0; i<N; i++)
			for(int j=min(2000*i, sum); j>=0; j--)
				if(isPos[j]) isPos[j+Nr[i]] = true;
		int val = -1;
		for(int i=E; i<=sum; i++) if(isPos[i]) {val = i; break;}
		printf("%d\n", val);

		for(int i=0; i<=sum; i++) isPos[i] = false;
	}
	return 0;
}
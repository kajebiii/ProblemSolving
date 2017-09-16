#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;

const int MAX_N = 2e5 + 100;

char S[3][MAX_N]; int N[3];
int F[MAX_N];
int main() {
	for(int j=0; j<3; j++) scanf("%s", S[j]+1), N[j] = strlen(S[j]+1);
	F[1] = 0;
	for(int i=2, k=0; i<=N[2]; i++) {
		while(k && S[2][k+1] != S[2][i]) k = F[k];
		if(S[2][k+1] == S[2][i]) k++;
		F[i] = k;
	}
	bool isCan = true;
	for(int l=0; l<2; l++) {
		bool nowCan = false;
		for(int i=1, k=0; i<=N[l]; i++) {
			while(k && S[2][k+1] != S[l][i]) k = F[k];
			if(S[2][k+1] == S[l][i]) k++;
			if(k == N[2]) {nowCan = true; break;}
		}
		if(!nowCan) {isCan = false; break;}
	}
	puts(isCan?"YES":"NO");
	return 0;
}
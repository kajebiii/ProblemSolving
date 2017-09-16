#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 5e1 + 10;

int N, Nr[MAX_N], S;

int main() {
	while(scanf("%d", &N) == 1) {
		for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
		scanf("%d", &S);

		for(int i=0; i<N; i++) {
			int now = Nr[i], ix = i;
			for(int j=i+1; j<min(N, i+S+1); j++) 
				if(now < Nr[j]) now = Nr[j], ix = j;
			for(int j=ix; j>=i+1; j--) Nr[j] = Nr[j-1];
			Nr[i] = now; S -= (ix - i);
		}
		for(int i=0; i<N; i++) printf("%d ", Nr[i]); puts("");
	}
	return 0;
}
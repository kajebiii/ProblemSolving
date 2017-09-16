#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 2e4 + 100;

typedef long long ll;
int N; ll Nr[MAX_N];

int main() {
	scanf("%d", &N); for(int i=0; i<N; i++) scanf("%lld", &Nr[i]);
	sort(Nr, Nr+N);
	bool isCan = false;
	for(int i=2; i<N; i++) if(Nr[i] < Nr[i-1] + Nr[i-2]) isCan = true;
	if(isCan) puts("possible");
	else puts("impossible");
	return 0;
}
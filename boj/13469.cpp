#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	if(n == 1) {puts("no"); return 0;}
	int memo = n;
	for(int i=2; i*i<=n; i++) if(n % i == 0) {
		while(n % i == 0) n /= i;
		break;
	}
	if(n == 1 || memo == n) puts("yes");
	else puts("no");
	return 0;
}
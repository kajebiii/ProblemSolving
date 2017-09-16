#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

ll X, Y, A, B;
int main() {
	scanf("%lld%lld%lld%lld", &X, &Y, &A, &B);
	if(A*2 <= B) printf("%lld\n", (X+Y) * A);
	else 
	{
		if(A <= B)
			printf("%lld\n", min(X, Y) * B + (X+Y-min(X,Y)*2) * A);
		else
			printf("%lld\n", (max(X, Y) - (X+Y)%2) * B + (X+Y)%2 * A);
	}
	return 0;
}
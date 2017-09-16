#include <stdio.h>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef long double ld;

int N, A[3];
int main()
{
	scanf("%d", &N); for(int i=0; i<3; i++) scanf("%d", &A[i]);
	ld val = -1;
	for(ld l=0, r=(1e9) + 10, cnt=0; cnt<1000; cnt+=1)
	{
		ld m = (l+r) / 2;
		ll now = 1;
		for(int i=0; i<3; i++) 
			now *= (ll)(A[i] / m);
		if(now >= N)
			l = m;
		else
			r = m;
		val = m;
	}
	printf("%.15Lf\n", val);
	return 0;
}
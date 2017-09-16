#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_P = 1e7 + 100;

typedef long long ll;

bool notP[MAX_P];
ll A, B;
int Ans = 0;

int main()
{
	scanf("%lld%lld", &A, &B);
	notP[1] = true;
	for(int i=2; i<MAX_P; i++) if(notP[i] == false)
	{
		for(int j=i*2; j<MAX_P; j+=i) notP[j] = true;
		ll now = 1ll * i * i;
		while(now <= B)
		{
			if(now >= A) Ans++;
			if(now > 1ll * MAX_P * MAX_P / i) break;
			now *= i;
		}
	}
	printf("%d\n", Ans);
	return 0;
}
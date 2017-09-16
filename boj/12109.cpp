#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 5e5 + 500;

int N, Nr[MAX_N];
int main() {
	scanf("%d", &N); for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	sort(Nr+1, Nr+N+1, [&](int &a, int &b) {return a > b;});
	int ans = 0;
	for(int i=1; i<=N; i++)
		if(i <= Nr[i]) ans = i;
	printf("%d\n", ans);
	return 0;
}
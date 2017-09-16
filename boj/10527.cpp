#include <stdio.h>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map<string, int> Mp[2];

int main()
{
	int N; scanf("%d", &N);
	for(int k=0; k<2; k++) for(int i=0; i<N; i++)
	{
		char state[20];
		scanf("%s", state);
		Mp[k][state]++;
	}

	int ans = 0;
	for(auto &x : Mp[0])
		ans += min(Mp[0][x.first], Mp[1][x.first]);

	printf("%d\n", ans);
	return 0;
}

#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

map<char, int> Mp;
int main() {
	Mp['A'] = 4;
	Mp['K'] = 3;
	Mp['Q'] = 2;
	Mp['J'] = 1;
	Mp['X'] = 0;

	int N, Ans = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		char getIn[22]; scanf("%s", getIn);
		for(int j=0; getIn[j]; j++)
			Ans += Mp[getIn[j]];
	}
	printf("%d\n", Ans);
	return 0;
}
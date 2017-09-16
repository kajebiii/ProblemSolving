#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 3e3 + 100;

int N, Nr[MAX_N];
int main() {
	while(scanf("%d", &N) == 1) {
		for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
		vector<int> list;
		for(int i=1; i<N; i++) list.push_back(abs(Nr[i] - Nr[i-1]));
		sort(list.begin(), list.end());
		bool isCan = true;
		for(int i=0; i<N-1; i++) if(list[i] != (i+1)) {isCan = false; break;}
		if(isCan) puts("Jolly");
		else puts("Not jolly");
	}
	return 0;
}
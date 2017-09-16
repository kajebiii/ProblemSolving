#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int MAX_N = (1 << 20) + 100;

int P, N, Nr[MAX_N], Memo[MAX_N], Lv;
map<int, int> Mp;
int main() {
	scanf("%d", &Lv); N = (1<<Lv); 
	for(int i=0; i<N; i++) scanf("%d", &Nr[i]), Memo[i] = Nr[i];
	sort(Nr, Nr+N);
	P = 1; Lv++;
	for(int i=0; i<N; i++) {
		if(i == P-1) {
			P *= 2;
			Lv--;
		}
		Mp[Nr[i]] = Lv;
	}
	for(int i=0; i<N; i++) printf("%d ", Mp[Memo[i]]);
	return 0;
}
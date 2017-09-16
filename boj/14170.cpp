#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 10;
int N, Q, Nr[MAX_N], Sum[MAX_N];
vector<int> Co;

const int fre = 0;
int main() {
	if(fre) freopen("haybales.in", "r", stdin);
	if(fre) freopen("haybales.out", "w", stdout);

	scanf("%d%d", &N, &Q); Co.push_back(-1); Co.push_back(1e9 + 1);
	for(int i=0; i<N; i++) scanf("%d", &Nr[i]), Co.push_back(Nr[i]);
	sort(Co.begin(), Co.end()); Co.erase(unique(Co.begin(), Co.end()), Co.end());
	for(int i=0; i<N; i++) Sum[lower_bound(Co.begin(), Co.end(), Nr[i]) - Co.begin()]++;
	for(int i=1; i<Co.size(); i++) Sum[i] += Sum[i-1];

	while(Q--) {
		int x, y; scanf("%d%d", &x, &y);
		x = lower_bound(Co.begin(), Co.end(), x) - Co.begin();
		y = upper_bound(Co.begin(), Co.end(), y) - Co.begin() - 1;
		printf("%d\n", Sum[y] - Sum[x-1]);
	}
	return 0;
}
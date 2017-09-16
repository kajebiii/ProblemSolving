#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e4 + 100;

int N, Nr[MAX_N], To[MAX_N], ToIx[MAX_N], Ix[MAX_N], Back[MAX_N];
int A[MAX_N], M, Past[MAX_N];

int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	for(int i=1; i<=N; i++) scanf("%d", &To[i]), ToIx[To[i]] = i;
	for(int i=1; i<=N; i++) Ix[i] = ToIx[Nr[i]], Back[Ix[i]] = Nr[i];

	A[M++] = 0;
	for(int i=1; i<=N; i++) {
		int ix = lower_bound(A, A+M, Ix[i]) - A;
		if(ix == M) M++;
		A[ix] = Ix[i];
		Past[A[ix]] = A[ix-1];
	}
	printf("%d\n", M-1);
	vector<int> List;
	int now = A[M-1];
	while(now > 0) {
		List.push_back(Back[now]);
		now = Past[now];
	}
	sort(List.begin(), List.end());
	for(int x : List) printf("%d ", x);
	return 0;
}
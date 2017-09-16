#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> List;
int ggcd(int a, int b) {return b==0?a:ggcd(b, a%b);}
int main() {
	for(int i=1; i<=1000; i++)
		for(int j=1+i%2; j<i; j+=2)
		{
			if(ggcd(i, j) > 1) continue;
			List.push_back(2*(2*i*j+i*i-j*j));
		}
	sort(List.begin(), List.end());
	int ix = -1;
	for(int i=1; i<List.size(); i++)
	{
		List[i] += List[i-1];
		if(List[i] > 1000000) {ix = i; break;}
	}
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		int x; scanf("%d", &x);
		printf("%d\n", upper_bound(List.begin(), List.begin() + ix, x) - List.begin());
	}
	return 0;
}
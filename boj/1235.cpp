#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>

using namespace std;

int N, M;
vector<string> S;

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		char getIn[111]; scanf("%s", getIn);
		S.push_back(getIn);
	}
	M = S[0].length();

	int res = -1;
	for(int l=1, r=M; l<=r; ) {
		int m = (l+r) >> 1;
		sort(S.begin(), S.end(), [&](auto &a, auto &b) {
			return a.substr(M-m, m) < b.substr(M-m, m);
		});
		bool isCan = true;
		for(int i=1; i<N; i++)
			if( S[i-1].substr(M-m, m) == S[i].substr(M-m, m) )
				isCan = false;
		if(isCan)
			res = m, r = m -1;
		else
			l = m+1;
	}
	printf("%d\n", res);
	return 0;
}
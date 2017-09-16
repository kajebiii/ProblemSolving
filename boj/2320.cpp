#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;

const int MAX_N = 16;

int Len[1<<MAX_N], Fast[1<<MAX_N];
bool Dy[1<<MAX_N][MAX_N];
bool Visit[1<<MAX_N][MAX_N];
string S[MAX_N]; int N;

bool getDy(int s, int k) {
	if(Visit[s][k]) return Dy[s][k];
	Visit[s][k] = true;

	bool isTrue = false;
	for(int before=s, now=(s-1)&s; before>0; before=now, now = (now-1) & now) {
		int ch = before - now, ix = Fast[ch];
		if(ix == k) continue;
		if(S[ix].back() == S[k].front())
			if(getDy(s - (1<<k), ix)) {isTrue = true; break;}
	}
	return Dy[s][k] = isTrue;
}
int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		char getIn[111]; scanf("%s", getIn);
		S[i] = getIn;
	}
	for(int i=0; i<N; i++) Fast[1<<i] = i;
	for(int i=0; i<N; i++) Visit[1<<i][i] = Dy[1<<i][i] = true;
	for(int i=0; i<N; i++) for(int j=0; j<(1<<i); j++)
		Len[j+(1<<i)] = Len[j] + S[i].length();
	int ans = 0;
	for(int i=0; i<N; i++) for(int j=0; j<(1<<N); j++)
		if(getDy(j | (1<<i), i))
			ans = max(ans, Len[j | (1<<i)]);
	printf("%d\n", ans);
	return 0;
}
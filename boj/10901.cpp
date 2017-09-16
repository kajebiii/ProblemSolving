#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <string.h>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

const int MAX_N = 1e5 + 100;

char S[MAX_N]; int N;
bool isAns(int a, int b) {
	if(a == b) return true;
	int m = (a+b) / 2, r = m+1;
	if((b-a) % 2 == 0) m--;
	if(isAns(a, m) == false) return false;

	for(int i=r-r; i<=b-r; i++) if(S[a+i] != S[r+i]) return false;
	return true;
}
void findAns(int a, int b) {
	if(a == b) {
		S[a]++;
		return;
	}
	int m = (a+b) / 2, r = m+1, mid = -1;
	if((b-a) % 2 == 0) {mid = m; m--;}
	bool isGood = isAns(a, m);
	if(isGood) {
		bool isPass = false;
		for(int i=r-r; i<=b-r; i++) {
			if(S[a+i] > S[r+i]) {isPass = true; break;}
			if(S[a+i] < S[r+i]) break;
		}
		if(isPass) {for(int i=r-r; i<=b-r; i++) S[r+i] = S[a+i];return;}
		if(mid != -1 && S[mid] < 'z') {
			S[mid]++;
			for(int i=r-r; i<=b-r; i++) S[r+i] = S[a+i];
			return;
		}
	}
	findAns(a, m);
	if(mid != -1) S[mid] = 'a';
	for(int i=r-r; i<=b-r; i++) S[r+i] = S[a+i];
	return;
}
int main() {
	scanf("%s", S+1); N = strlen(S+1);
//	N=91; for(int i=1; i<=N; i++) S[i] = 'a';
	findAns(1, N);
	printf("%s", S+1);
	return 0;
}

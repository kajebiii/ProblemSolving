#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
typedef pair<int, int> pi;

const int MAX_L = 99;

vector<int> A[2][2];
bool isEq(vector<int> &a, vector<int> &b) {
	for(int i=0; i<MAX_L; i++) if(a[i] != b[i]) return false;
	return true;
}
bool isZero(vector<int> &a) {
	for(int i=0; i<MAX_L; i++) if(a[i] != 0) return false;
	return true;
}
bool isLess(vector<int> &a, vector<int> &b) { // a < b
	for(int i=MAX_L-1; i>=0; i--) {
		if(a[i] < b[i]) return true;
		else if(a[i] > b[i]) return false;
	}
	return false;
}
void doMinus(vector<int> &a, vector<int> &b) { // a -= b;
	for(int i=0; i<MAX_L; i++) {
		a[i] -= b[i];
		if(a[i] < 0) a[i+1]--, a[i] += 10;
	}
}

int main() {
	rep(i, 2) rep(j, 2) {
		char val[MAX_L+1] = {0}; scanf("%s", val);
		A[i][j] = vector<int>(MAX_L, 0);
		for(int k=MAX_L, cnt = 0; k>=0; k--)
			if(val[k] != 0) A[i][j][cnt++] = val[k] - '0';
	}
	vector<int> bits[2];
	rep(j, 2) {
		while(1) {
//			for(int i=MAX_L-1; i>=0; i--) printf("[%d]", A[0][j][i]); puts("");
//			for(int i=MAX_L-1; i>=0; i--) printf("[%d]", A[1][j][i]); puts(""); puts("");
			if(isZero(A[1-j][j])) {
				for(int i=0; i<200; i++) bits[j].push_back(1-j);
				break;
			}
			if(isEq(A[0][j], A[1][j])) {
				bits[j].push_back(j);
				A[1-j][j][0] = 0;
				for(int i=0; i<200; i++) bits[j].push_back(1-j);
				break;
			}else {
				if(isLess(A[0][j], A[1][j])) {
					bits[j].push_back(0);
					doMinus(A[1][j], A[0][j]);
				} else {
					bits[j].push_back(1);
					doMinus(A[0][j], A[1][j]);
				}
			}
		}
	}
	for(int i=0; i<200; i++) if(bits[0][i] == bits[1][i]) printf("%d", bits[0][i]);
	return 0;
}
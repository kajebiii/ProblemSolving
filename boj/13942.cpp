#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <assert.h>

using namespace std;

const int MAX_K = 5e1 + 5, MAX_N = 1e6 + 100;;

typedef pair<int, int> pi;

int K, Nr[MAX_K], N;
char S[MAX_N];
vector<int> Fast[MAX_N]; int Right[MAX_N];
double getVal(int a, int b) {
	vector<double> val;
	for(int x : Fast[a]) val.push_back(getVal(x, Right[x]));
	if(val.size() == 0) return Nr[1];
	if(S[Right[a+1]+1] == '+') {
		double sum = 0;
		for(auto x : val) sum += x;
		double res = min(sum, (double)Nr[val.size()]);
		return res;
	}else{
		sort(val.begin(), val.end());
		int k = val.size();
		double res = 1, sum = Nr[k];
		for(auto x : val) {
			if(x <= sum / k) {
				res *= x;
				sum -= x; k--;
			} else {
				res *= sum / k;
				sum -= sum / k; k--;
			}
		}
		return res;
	}
	assert(true);
	return -1;
}
int main() {
	scanf("%d", &K); for(int i=1; i<=K; i++) scanf("%d", &Nr[i]);
	scanf("%s", S); N = strlen(S);
	stack<int> St;
	for(int i=0; i<N; i++) {
		if(S[i] == '(') St.push(i);
		else if(S[i] == ')') {
			int l = St.top(); St.pop();
			Right[l] = i;
			if(!St.empty())
				Fast[St.top()].push_back(l);
		}
	}
	printf("%f", getVal(0, N-1));
	return 0;
}
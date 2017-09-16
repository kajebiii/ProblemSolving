#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

typedef pair<int, int> pi;

int N = 4, cnt = 0;
string S = "ABCDEF";
map<char, pi> Mp;
int Nr[5];

int main() {
	for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++)
		Mp[S[cnt++]] = make_pair(i, j);
	cin >> S;
	Nr[1] = 1; Nr[4] = 2;
	for(char x : S) swap(Nr[Mp[x].first], Nr[Mp[x].second]);
	for(int k=1; k<=2; k++) for(int i=1; i<=N; i++) if(Nr[i] == k) printf("%d\n", i);
	return 0;
}
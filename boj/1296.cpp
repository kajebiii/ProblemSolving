#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX_N = 99;

string You;
int N; string Other[MAX_N];
char C[4] = {'L', 'O', 'V', 'E'};
int getCnt(string &s, char k)
{
	int cnt = 0;
	for(char &x : s) if(x == k) cnt++;
	return cnt;
}
int main()
{
	cin >> You; scanf("%d", &N);
	for(int i=0; i<N; i++) cin >> Other[i];
	sort(Other, Other+N);

	int ansV = -1; string ans;
	for(int i=0; i<N; i++)
	{
		int cnt[4];
		for(int j=0; j<4; j++) cnt[j] = getCnt(You, C[j]) + getCnt(Other[i], C[j]);

		int now = 1;
		for(int x=0; x<4; x++) for(int y=x+1; y<4; y++) now *= cnt[x] + cnt[y], now %= 100;
		if(ansV < now) ans = Other[i], ansV = now;
	}

	cout << ans;

	return 0;
}
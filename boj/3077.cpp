#include <stdio.h>
#include <string>
#include <map>
#include <iostream>

using namespace std;

const int MAX_N = 2500 + 50;

map<string, int> M;
int N, Nr[MAX_N];

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		string S; cin >> S;
		M[S] = i;
	}
	for(int i=0; i<N; i++)
	{
		string S; cin >> S;
		Nr[i] = M[S];
	}

	int cnt = 0;
	for(int i=0; i<N; i++) for(int j=i+1; j<N; j++)
		if(Nr[i] < Nr[j]) cnt++;
	printf("%d/%d\n", cnt, N*(N-1)/2);
	return 0;
}
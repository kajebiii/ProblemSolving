#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1e2 + 10;

int N; string S[MAX_N], temp[MAX_N];
bool possible = true;
vector<int> Ed[99]; int inD[99], Ans[99];

void initGraph(int a, int b, int k)
{
	if(a > b) return;
	for(int i=a+1; i<=b; i++)
		if(S[i].size() <= k) {possible = false; return;}
	if(S[a].size() <= k) return initGraph(a+1, b, k);

	vector<char> List; int past = a;
	for(int i=a; i<=b; i++)
		if(i == b || S[i][k] != S[i+1][k])
		{
			List.push_back(S[i][k]);
			initGraph(past, i, k+1);
			past = i+1;
		}

	for(int i=1; i<List.size(); i++)
		Ed[List[i-1]-'a'].push_back(List[i]-'a'), inD[List[i]-'a']++;
	return;
}
int main()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++)
	{
		char getIn[111]; scanf("%s", getIn);
		temp[i] = S[i] = getIn;
	}
	for(int i=1, x; i<=N; i++) scanf("%d", &x), S[i] = temp[x];
	initGraph(1, N, 0);

	queue<int> Q;
	for(int i=0; i<26; i++) if(inD[i] == 0) Q.push(i);

	int cnt = 0;
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		Ans[v] = cnt++;
		for(int w : Ed[v])
			if(--inD[w] == 0)
				Q.push(w);
	}

	if(cnt != 26 || possible == false) puts("NE");
	else
	{
		puts("DA");
		for(int i=0; i<26; i++) printf("%c", Ans[i]+'a');
	}
	return 0;
}
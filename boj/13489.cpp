#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 16;

int Dy[1<<MAX_N], N, Cnt[MAX_N][26];
bool Visit[1<<MAX_N];

int getDy(int s)
{
	if(Visit[s]) return Dy[s];
	Visit[s] = true;
	vector<int> list;
	for(int i=0; i<N; i++) if(s & (1<<i)) list.push_back(i);
	int cnt = 1;
	for(int k=0; k<26; k++)
	{
		int now = 0x7fffffff;
		for(int x : list) now = min(now, Cnt[x][k]);
		cnt += now;
	}
	if(list.size() == 1) return Dy[s] = cnt;
	int val = 0x7fffffff;
	for(int i=(s-1)&s; i>0; i=(i-1)&s)
		val = min(val, getDy(i) + getDy(s-i) - cnt);
	return Dy[s] = val;
}

int main()
{
	scanf("%d", &N);
	for(int o=0; o<N; o++)
	{
		char getIn[1111111];
		scanf("%s", getIn);
		for(int i=0; getIn[i]; i++)
			Cnt[o][getIn[i]-'a']++;
	}
	printf("%d\n", getDy((1<<N)-1));
	return 0;
}
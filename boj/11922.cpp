#include <stdio.h>
#include <map>

using namespace std;

int S[8][2] ={
	{11, 11},
	{ 4,  4},
	{ 3,  3},
	{20,  2},
	{10, 10},
	{14,  0},
	{ 0,  0},
	{ 0,  0},
};
map<char, int> M;

int main()
{
	char c[8] = {'A', 'K', 'Q', 'J', 'T', '9', '8', '7'};
	for(int i=0; i<8; i++) M[c[i]] = i;
	int N; char x; scanf("%d %c", &N, &x);
	int ans = 0;
	for(int n=0; n<N; n++)
	{
		for(int i=0; i<4; i++)
		{
			char in[10]; scanf("%s", in);
			ans += S[M[in[0]]][1 - (in[1] == x)];
		}
	}
	printf("%d\n", ans);
	return 0;
}
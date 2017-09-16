#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int MAX_N = 8e1;

int N = 26 * 2;
bool D[MAX_N][MAX_N];
map<char, int> ci;
map<int, char> ic;

int main()
{
	int M; scanf("%d", &M);
	for(int i=0; i<26; i++)
	{
		ic[ci['A'+i] = i   ] = 'A'+i;
		ic[ci['a'+i] = i+26] = 'a'+i;
	}
	for(int _=0; _<M; _++)
	{
		scanf(" ");
		char x, y;
		scanf("%c => %c", &x, &y);
		D[ci[x]][ci[y]] = true;
	}
	for(int k=0; k<52; k++) for(int i=0; i<52; i++) for(int j=0; j<52; j++)
		if(D[i][k] && D[k][j]) D[i][j] = true;
	vector<pair<char, char>> Ans;
	for(int i=0; i<52; i++) for(int j=0; j<52; j++) if(i != j && D[i][j])
		Ans.push_back(make_pair(ic[i], ic[j]));
	printf("%d\n", (int)Ans.size());
	for(auto &t : Ans) printf("%c => %c\n", t.first, t.second);
	return 0;
}
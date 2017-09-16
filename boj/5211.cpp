#include <string>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	string S;
	cin >> S;
	S = "|" + S;
	int a = 0, c = 0, k = 0;
	for(int i=0; i<S.length(); i++)
		if(S[i] == '|')
		{
			char x = S[i+1];
			if(x == 'A' || x == 'D' || x == 'E') a++;
			if(x == 'C' || x == 'F' || x == 'G') c++;
		}
	if(a == c)
	{
		char x = S[S.length()-1];
		if(x == 'A' || x == 'D' || x == 'E') a++;
		if(x == 'C' || x == 'F' || x == 'G') c++;
	}
	printf("%s", (a<c?"C-major":"A-minor"));
	return 0;
}
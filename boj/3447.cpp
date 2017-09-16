#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string S;
	while(getline(cin, S))
	{
		int pos = -1;
		while((pos = S.find("BUG")) != -1)
			S = S.substr(0, pos) + S.substr(pos+3, S.length() - pos - 3);
		cout << S << endl;
	}
	return 0;
}
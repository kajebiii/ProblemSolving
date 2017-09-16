// =====================================================================================
//
//       Filename:  5637.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 03:05:21
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <string>
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

string S;
string Ans = "";

int main()
{
	while(cin >> S)
	{
		if(S.compare("E-N-D") == 0) break;
		bool flag = false;
		int cnt = 0, start = -1, end = 0;
		for(char x : S)
		{
			if(!(x >= 'A' && x <= 'Z') && !(x == '-') && !(x >= 'a' && x <= 'z'))
				start = -1;
			else
			{
				if(start == -1) start = cnt;
				end = cnt;
				if(Ans.length() < (S.substr(start, end-start+1)).length())
					Ans = (S.substr(start, end-start+1));
			}
			cnt++;
		}
	}
	transform(Ans.begin(), Ans.end(), Ans.begin(), ::tolower);
	cout << Ans;
	
	return 0;
}

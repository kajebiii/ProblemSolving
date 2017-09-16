// =====================================================================================
//
//       Filename:  4613.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/13/2016 23:17:08
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int main()
{
	while(true)
	{
		string s;
		getline(cin, s);

		int result = 0;
		for(int i=0; i<s.length(); i++)
		{
			int x = s[i] - 'A' + 1;
			if(s[i] == '#')
				return 0;
			if(s[i] == ' ' || s[i] == '\n')
				x = 0;
			result += (i+1) * x;
		}
		printf("%d\n", result);
	}
	return 0;
}





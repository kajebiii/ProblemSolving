// =====================================================================================
//
//       Filename:  8911.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 18:37:09
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cx[4] = {1, 0, -1, 0};
int cy[4] = {0, 1, 0, -1};
int Data[3][999];

int main()
{
	int T; cin >> T;
	for(; T--; )
	{
		string S; cin >> S;
		int cnt = 1;
		Data[0][0] = Data[1][0] = Data[2][0] = 0;
		for(char x : S)
		{
			if(x == 'F' || x == 'B')
			{
				int mul = (x == 'F')?1:-1;
				Data[0][cnt] = Data[0][cnt - 1] + mul * cx[Data[2][cnt - 1]];
				Data[1][cnt] = Data[1][cnt - 1] + mul * cy[Data[2][cnt - 1]];
				Data[2][cnt] = Data[2][cnt - 1]; 
				cnt++;
			}
			else if(x == 'L')
				Data[2][cnt-1] = (Data[2][cnt-1] + 3) % 4;
			else
				Data[2][cnt-1] = (Data[2][cnt-1] + 1) % 4;	
		}
		printf("%d\n", (Data[0][max_element(Data[0], Data[0]+cnt) - Data[0] ] - Data[0][min_element(Data[0], Data[0]+cnt) - Data[0]])
			 		 * (Data[1][max_element(Data[1], Data[1]+cnt) - Data[1] ] - Data[1][min_element(Data[1], Data[1]+cnt) - Data[1]]));
	}

	return 0;
}













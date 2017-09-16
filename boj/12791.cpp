// =====================================================================================
//
//       Filename:  12791.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/22/2016 17:33:50
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> pi;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;

string S[3000];
int main() {
	S[1967] = "DavidBowie";
	S[1969] = "SpaceOddity";
	S[1970] = "TheManWhoSoldTheWorld";
	S[1971] = "HunkyDory";
	S[1972] = "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars";
	S[1973] = "AladdinSane";
	S[1973] = "PinUps";
	S[1974] = "DiamondDogs";
	S[1975] = "YoungAmericans";
	S[1976] = "StationToStation";
	S[1977] = "Low";
	S[1977] = "Heroes";
	S[1979] = "Lodger";
	S[1980] = "ScaryMonstersAndSuperCreeps";
	S[1983] = "LetsDance";
	S[1984] = "Tonight";
	S[1987] = "NeverLetMeDown";
	S[1993] = "BlackTieWhiteNoise";
	S[1995] = "1.Outside";
	S[1997] = "Earthling";
	S[1999] = "Hours";
	S[2002] = "Heathen";
	S[2003] = "Reality";
	S[2013] = "TheNextDay";
	S[2016] = "BlackStar";
	int N; cin >> N;
	for(; N--; )
	{
		int x, y; scanf("%d%d", &x, &y);
		int cnt = 0;
		for(int i=x; i<=y; i++)
			if(S[i] != "") cnt = cnt + ((i == 1973 || i == 1977) ? 2 : 1);
		printf("%d\n", cnt);
		for(int i=x; i<=y; i++)
			if(S[i] != "")
			{
				if(i == 1973)
					cout << i << " " << "AladdinSane" << endl;
				if(i == 1977)
					cout << i << " " << "Low" << endl;
				cout << i << " " << S[i] << endl;
			}
	}
	return 0;
}











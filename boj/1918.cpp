// =====================================================================================
//
//       Filename:  1918.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/12/2016 18:23:09
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
#include <math.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

map<char, int> Ord;
string post(string s)
{
	stack<string> rand;
	stack<char> rator;
	for(int i=0; i<=s.length(); i++)
	{
		if(s[i] == '(')
		{
			int cnt = 1;
			int start = i, length = 1;
			while(cnt > 0)
			{
				i++; length++;
				if(s[i] == '(') cnt++;
				else if(s[i] == ')') cnt--;
			}
			rand.push(post(s.substr(start+1, length-2)));
		}
		else if(s[i] >= 'A' && s[i] <= 'Z')
			rand.push(s.substr(i, 1));
		else
		{
			while(!rator.empty() && (i==s.length() || Ord[rator.top()] >= Ord[s[i]]))
			{
				string B = rand.top(); rand.pop();
				string A = rand.top(); rand.pop();
				string C = A + B + rator.top(); rator.pop();
				rand.push(C);
			}
			if(i == s.length()) break;
			rator.push(s[i]);
		}
	}
	return rand.top();
}
int main() {
	Ord['*'] = Ord['/'] = 1;
	Ord['+'] = Ord['-'] = 0;
	string S; cin >> S;
	cout << post(S);
	return 0;
}











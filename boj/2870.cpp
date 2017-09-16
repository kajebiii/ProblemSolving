#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<string> Ans;
bool cmp(string &a, string &b)
{
	if(a.length() != b.length()) 
		return a.length() < b.length();
	for(int i=0; i<a.length(); i++)
		if(a[i] != b[i]) return a[i] < b[i];
	return false;
}
int main()
{
	scanf("%d", &N);
	for(int tc=0; tc<N; tc++)
	{
		string S; cin >> S;
		bool first = true;
		for(char x : S)
		{
			if(x >= '0' && x <= '9')
			{
				if(first) Ans.push_back("");
				(Ans.back()).append(string(1, x));
				first = false;
			}else first = true;
		}
	}
	for(string &s : Ans)
	{
		int start = -1;
		for(int i=0; i<s.length(); i++)
			if(s[i] != '0') {start = i; break;}
		if(start == -1) start = s.length() - 1;
		s = s.substr(start, s.length() - start);
	}
	sort(Ans.begin(), Ans.end(), cmp);
	for(string s : Ans) cout << s << endl;
	return 0;
}
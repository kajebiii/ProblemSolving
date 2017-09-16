
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <map>

using namespace std;

string charToString(char *A)
{
	string result = "";
	for (int i = 0; A[i] != 0; i++)
		result += A[i];
	return result;
}

int Child[1111][2];
string What[1111];
int Cnt;
map<string, int> M;
int Dy[1111][2222];
string P;

int getAns(int m, int find)
{
	if (find == P.size()) return find;
	int last = find;
	if (Dy[m][find] != -1) return Dy[m][find];
	if (Child[m][0] == 0 && Child[m][1] == 0)
	{
		int PN = P.size();
		int WN = What[m].size();
		for (int i = 0; last < PN && i < WN; i++)
		{
			if (P[last] == What[m][i]) last++;
		}
		Dy[m][find] = last;
		return last;
	}
	last = getAns(Child[m][0], last);
	last = getAns(Child[m][1], last);
	Dy[m][find] = last;
	return last;
}

int main()
{

	int T, K;
	scanf("%d", &T);
	memset(Dy, -1, sizeof(Dy));
	for (; T--;)
	{
		scanf("%d\n", &K);
		Cnt = 0;
		for (int q = 0; q < K; q++)
		{
			char getInput[99];
			fgets(getInput, 99, stdin);

			bool isPlus = false;
			for (int i = 0; getInput[i]; i++)
			{
				if (getInput[i] == '+')
					isPlus = true;
			}

			if (isPlus)
			{
				char aa[9], bb[9], cc[9];
				sscanf(getInput, "%s = %s + %s", aa, bb, cc);
				string a = charToString(aa);
				string b = charToString(bb);
				string c = charToString(cc);

				if (M.count(a) == 0) M[a] = ++Cnt;
				if (M.count(b) == 0) M[b] = ++Cnt;
				if (M.count(c) == 0) M[c] = ++Cnt;

				Child[M[a]][0] = M[b];
				Child[M[a]][1] = M[c];
			}
			else
			{
				char aa[9], bb[9];
				sscanf(getInput, "%s = %s", aa, bb);
				string a = charToString(aa);
				string b = charToString(bb);
				if (M.count(a) == 0) M[a] = ++Cnt;
				What[M[a]] = b;
			}
		}

		string T;
		cin >> T;
		cin >> P;

		int ans = getAns(M[T], 0);


		if (ans < P.size())
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}

		int PN = P.size();

		for (int i = 1; i <= Cnt; i++)
		{
			Child[i][0] = Child[i][1] = 0;
			What[i] = "";
			for (int j = 0; j < PN; j++)
				Dy[i][j] = -1;
		}
		M.clear();

	}

	return 0;
}

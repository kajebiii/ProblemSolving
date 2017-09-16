/*
#include <stdio.h>
#include <string.h>

int provjeri_jedan_set(int g1, int g2, int koji_set, const char *ime1, const char *ime2, int pob[2])
{
	if(g1 == g2) return 0;

	if(g1 < g2) {
		int t; const char *p;

		t = g1; g1 = g2; g2 = t;
		p = ime1; ime1 = ime2; ime2 = p;
		++pob[1];
	}
	else
		++pob[0];

	if(strcmp(ime2, "federer") == 0) return 0;

	printf("%d %d %d\n", g1, g2, koji_set);
	if(g1 < 6) return 0;
	if(g1 == 6) return g2 <= 4;
	if(g1 == 7 && koji_set < 3) return g2 == 5 || g2 == 6;
	if(g1 >= 7 && koji_set == 3) return g1 == g2+2;
	return 0;
}

int main()
{
	char ime1[21], ime2[21];
	int n, i;
	scanf("%s%s", ime1, ime2);
	scanf("%d\n", &n);

	for(i=0; i<n; ++i) {
		int ok = 1;
		char red[100];
		char *p = red;
		int pob[2] ={0, 0};
		int koji_set, g1, g2, ucitano;

		fgets(red, sizeof red, stdin);

		for(koji_set=1; sscanf(p, "%d:%d%n", &g1, &g2, &ucitano) == 2; ++koji_set) {
			p += ucitano;
			ok &= pob[0] < 2 && pob[1] < 2;
			ok &= provjeri_jedan_set(g1, g2, koji_set, ime1, ime2, pob);
			printf("%d\n", ok);
		}
		ok &= pob[0] == 2 || pob[1] == 2;

		puts(ok ? "da" : "ne");
	}

	return 0;
}
*/

#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string S[2]; int N, W[2];
bool isGood(int x, int y, int w)
{
	if(x == y) return false;
	if(x < y && S[0] == "federer") return false;
	if(x > y && S[1] == "federer") return false;
	if(x < y) W[1]++; else W[0]++;
	if(x < y) swap(x, y);
	if(x < 6) return false;
	if(x == 6) return y <= 4;
	if(x == 7 && w <= 2) return y == 5 || y == 6;
	if(x >= 7 && w == 3) return y == x-2;
	return false;
}
int main()
{
	for(int i=0; i<2; i++) cin >> S[i];
	scanf("%d", &N); scanf(" ");
	for(int n=0; n<N; n++)
	{
		char getP[99];
		char *p = getP;
		W[0] = W[1] = 0;
		fgets(getP, 99, stdin);
		bool isTrue = true;
		for(int x, y, l, w=1; sscanf(p, "%d:%d%n", &x, &y, &l) == 2; w++)
		{
			p += l;
			isTrue &= (W[0] < 2 && W[1] < 2);
			isTrue &= isGood(x, y, w);
		}
		isTrue &= (W[0] == 2 || W[1] == 2);
		if(isTrue) puts("da");
		else puts("ne");
	}
	return 0;
}

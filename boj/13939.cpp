#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX_S = 1111;

int N; char S[MAX_S];
int main() {
	scanf("%d", &N); scanf(" ");
	fgets(S, MAX_S, stdin);
	char *p = S;
	while(N--) {
		char word[MAX_S]; int cnt = 0;
		int ans = 0;
		while(sscanf(p, "%s%n", &word, &cnt) == 1) {
			p += cnt;
			int l = strlen(word);
			bool finish = false;
			if(word[l-1] == '.' || word[l-1] == '?' || word[l-1] == '!') {
				finish = true;
				word[l-1] = 0;
				l--;
			}

			bool check = true;
			for(int i=1; i<l; i++) if(word[i] < 'a' || word[i] > 'z') check = false;
			if(check && word[0] >= 'A' && word[0] <= 'Z') ans++; 
			if(finish) break;
		}
		printf("%d\n", ans);
	}
	return 0;
}
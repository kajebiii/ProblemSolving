#include <stdio.h>

char Data[2222];
void printS(int s)
{
	for(int i=0; i<s; i++) printf(" ");
}
int main()
{
	scanf("%s", Data);
	int space = 0;
	for(int i=0; Data[i]!=0; i++)
	{
//		printf("%d : %c\n", i, Data[i]);
		if(Data[i] == '{')
		{
			printf("%c\n", Data[i]);
			space += 2;
			if(Data[i+1] != '}')
				printS(space);
		}
		else if(Data[i] == '}')
		{
			if(Data[i-1] != '{')
				printf("\n");
			space -= 2;
			printS(space);
			printf("%c", Data[i]);
		}
		else if(Data[i] == ',')
		{
			printf(",\n");
			printS(space);
		}
		else
		{
			printf("%c", Data[i]);
		}
	}
	return 0;
}
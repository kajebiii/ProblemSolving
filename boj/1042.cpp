 
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
 
using namespace std;
 
const int MAX_L = 3000;
const int MAX_N = 60;
const int INF = 0x7fffffff;
const int MOD = (1e9) + 7;
 
char DNA[MAX_L];
int L, N, Nr;
 
vector<int> DataIndex[MAX_N];
set<int> DNAIndex[5];
 
struct DATA
{
    char codon[3];
    string amino;
    int nr;
     
    const bool operator<(const DATA& a) const
    {
        return amino < a.amino;
    }
     
}Data[MAX_N];
 
int Dy[MAX_L];
 
const int Change(const char c)
{
    switch (c)
    {
        case 'A':
            return 0;
        case 'G':
            return 1;
        case 'T':
            return 2;
        case 'C':
            return 3;
    }
    return 4;
}
 
int main()
{
    scanf("%s", DNA+1);
    L = (int)strlen(DNA+1);
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%s", Data[i].codon);
        cin >> Data[i].amino;
    }
 
    sort(Data, Data + N);
 
    Nr = 0;
    for(int i=0; i<N; i++)
    {
        if(i == 0)
            Data[i].nr = Nr;
        else
        {
            if(Data[i].amino != Data[i-1].amino)
                Nr = Nr + 1;
            Data[i].nr = Nr;
        }
        DataIndex[Nr].push_back(i);
    }
 
    for(int i=1; i<=L; i++)
        DNAIndex[Change(DNA[i])].insert(i);
 
    Dy[0] = 1;
    for(int i=0; i<=L; i++)
    {
        for(int nr=0; nr<=Nr; nr++)
        {
            int minIndex = INF;
            for(int ix : DataIndex[nr])
            {
                int nowIndex = i;
                for(int k=0; k<3; k++)
                {
                    int change = Change(Data[ix].codon[k]);
                    set<int>::iterator it = DNAIndex[change].upper_bound(nowIndex);
                    if(it == DNAIndex[change].end())
                    {
                        nowIndex = INF;
                        break;
                    }
                    else
                        nowIndex = *it;
                }
                minIndex = min(minIndex, nowIndex);
            }
            if(minIndex != INF)
                Dy[minIndex] = (Dy[minIndex] + Dy[i]) % MOD;
        }
    }
 
    int result = 0;
    for(int i=1; i<=L; i++)
        result = (result + Dy[i]) % MOD;
     
    printf("%d\n", result);
     
    return 0;
}
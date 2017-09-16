//
//  main.cpp
//  11014
//
//  Created by KJBS2 on 2016. 1. 22..
//  Copyright (c) 2016년 KJBS2. All rights reserved.
//
 
#include <stdio.h>
#include <vector>
 
using namespace std;
 
const int MAX_N = (int)1e2;
 
int N, M;
char Map[MAX_N][MAX_N];
int Nr[MAX_N][MAX_N];
int NrMax[2];
 
int CX[6] = {-1, 0, 1, -1, 0, 1};
int CY[6] = {-1, -1, -1, 1, 1, 1};
 
vector<int> V[2][MAX_N*MAX_N];
 
vector<int> Match;
vector<bool> Visit;
 
bool FindMatch(int v) {
    if(Visit[v] == true) return false;
     
    Visit[v] = true;
     
    for(auto nv : V[0][v]) {
        if(Match[nv] == -1 || FindMatch(Match[nv])) {
            Match[nv] = v;
            return true;
        }
    }
     
    return false;
}
 
void PROCESS() {
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        scanf("%s", Map[i]+1);
    for(int i=0; i<=N+1; i++)
        Map[i][0] = Map[i][M+1] = 'x';
    for(int i=0; i<=M+1; i++)
        Map[0][i] = Map[N+1][i] = 'x';
     
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++) {
            Nr[i][j] = ( (j-1) / 2 ) * N + i;
            NrMax[j%2]++;
        }
     
    int all = 0;
     
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++) {
            if(Map[i][j] == 'x') continue;
            all++;
            for(int k=0; k<6; k++) {
                int nx = i + CX[k];
                int ny = j + CY[k];
                if(Map[nx][ny] == 'x') continue;
                V[j%2][Nr[i][j]].push_back(Nr[nx][ny]);
            }
        }
     
    Match = vector<int>(NrMax[1] + 1, -1);
     
    int size = 0;
    for(int i=1; i<=NrMax[0]; i++) {
        Visit = vector<bool>(NrMax[0] + 1, false);
        if( FindMatch(i) )
            size++;
    }
     
    printf("%d\n", all - size);
     
    for(int k=0; k<2; k++)
        for(int i=1; i<=NrMax[k]; i++)
            V[k][i] = vector<int>();
    NrMax[0] = NrMax[1] = 0;
}
 
int main() {
    int T;
    scanf("%d", &T);
     
    for(int i=0; i<T; i++)
        PROCESS();
     
    return 0;
}
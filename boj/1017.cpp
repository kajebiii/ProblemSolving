//
//  main.cpp
//  1017
//
//  Created by KJBS2 on 2/7/16.
//  Copyright (c) 2016 KJBS2. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_NR = (int)3e3;
const int MAX_N = (int)9e1;

int N;
vector<int> Numbers[2];
vector<bool> isPrime = vector<bool>(MAX_NR+1, true);

bool isPairPrime(int ix0, int ix1) {
    return isPrime[Numbers[0][ix0] + Numbers[1][ix1]];
}

void Input() {
    scanf("%d", &N);
    
    int plus[2] = {0, 1};
    int multi[2] = {1, -1};
    int ix = -1;
    for(int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        
        if(i == 0) ix = x & 1;
        Numbers[plus[ix] + multi[ix] * (x & 1)].push_back(x);
    }
}

vector<int> match;
vector<bool> visit;
bool findMatch(int index) {
    if(visit[index] == true) return false;
    visit[index] = true;
    
    for(int i=0; i<N/2; i++) {
        if(!isPairPrime(index, i)) continue;
        
        if(match[i] == -1 || findMatch(match[i])) {
            match[i] = index;
            return true;
        }
    }
    return false;
}

void Process(vector<int> &Answer) {
    if(Numbers[0].size() != Numbers[1].size()) return;
    
    for(int i=2; i<=MAX_NR; i++) {
        if(isPrime[i] == false) continue;
        for(int j=i*2; j<=MAX_NR; j+=i)
            isPrime[j] = false;
    }
    
    match = vector<int>(N/2, -1);
    
    int result = 1;
    
    for(int j=1; j<N/2; j++) {
        visit = vector<bool>(N/2, false);
        
        if(findMatch(j))
            result++;
    }
    
    if(result != (N/2)) return;
    
    for(int i=0; i<N/2; i++) {
        visit = vector<bool>(N/2, false);
        if(!isPairPrime(0, i)) continue;
        
        if(match[i] == -1 || findMatch(match[i])) {
            match[i] = -1;
            Answer.push_back(Numbers[1][i]);
        }
    }
    
}

int main() {
    Input();
    
    vector<int> Answer;
    Process(Answer);
    if(Answer.size() == 0) printf("-1");
    
    sort(Answer.begin(), Answer.end());
    for(int value : Answer)
        printf("%d ", value);
    
    return 0;
}

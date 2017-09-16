 
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
 
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
 
using namespace std;
 
int main() {
    long long N; cin >> N;
    if(N % 2 == 0)
        printf("CY");
    else
        printf("SK");
    return 0;
}